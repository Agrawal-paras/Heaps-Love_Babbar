/*   
    APPROACH - 1- COMPARING ONE BY ONE AND FIND SMALLEST

->The idea is to pick the nodes of the final list one by one, by comparing heads of all K lists.

->Pick the list with the smallest head value, add that node to the final node and move the head pointer of that list one node ahead.

->Say you have chosen the list  A -> B-> C -> NULL. with the smallest head value. 
And currently your final list is E -> F -> G -> H-> NULL.

->Then you simply disconnect the node A from list A -> B -> C-> NULL, so it becomes B -> C-> NULL.
 And A to your final list E -> F -> G -> H -> A -> NULL.
 
->Repeat step 2, until all lists get empty.

->In this way, we get our final list.

    Time Complexity: O(N * K)
    Space Complexity: O(1)

    Where 'N' is the total number of Nodes.
    And 'K' is the number of lists.
*/

#include <limits.h>

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    Node<int> *head = NULL, *tail = NULL;

    while (true)
    {
        int check = INT_MAX;
        int index;

        for (int i = 0; i < k; i++)
        {
            if (listArray[i] != NULL)
            {
                int value = listArray[i]->data;
                if (value < check)
                {
                    check = value;
                    index = i;
                }
            }
        }

        // If check is INT_MAX, means all lists become empty.
        if (check == INT_MAX)
        {
            break;
        }

        Node<int> *curNode = listArray[index];
        listArray[index] = listArray[index]->next;
        curNode->next = NULL;

        if (head == NULL)
        {
            head = curNode;
            tail = curNode;
        }
        else
        {
            tail->next = curNode;
            tail = tail->next;
        }
    }

    return head;
}




/*  
    APPROACH -2 :-
    

Here we will perform a brute force of adding all the nodes in a separate list and then sort it.

->Traverse through all the linked lists and add each node in a different array.
->Sort the array.
->Make a new linked list and add all of the elements of the sorted array.



    Time Complexity: O(N * logN)
    Space Complexity: O(N)

    Where 'N' is the total number of Nodes.
*/

#include <algorithm>

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{

    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    vector<int> helper;

    // Insert nodes in a helper array.
    for (int i = 0; i < k; i++)
    {
        Node<int>* curNode = listArray[i];

        while (curNode!=NULL)
        {
           helper.push_back(curNode->data);
           curNode =  curNode->next;
        }
    }

    // Sort the array.
    sort(helper.begin(), helper.end());

    Node<int> *head = NULL, *tail = NULL;

    // Convert into a linked list.
    for (int i = 0; i < helper.size(); i++)
    {
        Node<int> *newNode = new Node<int>(helper[i]);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}







/*
    APPROACH 3-  USING PRIORITY QUEUE
   
   
The idea is to use priority queue to reduce searching time for list with smaller head value.

->We will maintain a priority queue for the head node of K list.
->The top of the queue gives the nodes with smaller value.
->We will add this head node into our final list and move the head pointer of that list to the next node of that list 
  and update it in our queue.
->We will repeat step 3 and 4, until the queue becomes empty.



    Time Complexity: O(N * logK)
    Space Complexity: O(K)

    Where 'N' is the total number of Nodes.
    And 'K' is the number of lists.
*/

#include <queue>

// Compare class for priority queue.
class compare
{
public:
    bool operator()(const Node<int> *first, const Node<int> *second)
    {
        return (first->data > second->data);
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    priority_queue<Node<int>*, vector<Node<int>*>, compare> helperPQ;

    // Push into the queue.
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            helperPQ.push(listArray[i]);
        }
    }

    Node<int> *head = NULL, *tail = NULL;

    // Add nodes while queue is non empty.
    while (helperPQ.size() > 0)
    {
        Node<int> *minNode = helperPQ.top();
        helperPQ.pop();

        if (minNode->next != NULL)
        {
            helperPQ.push(minNode->next);
            minNode->next = NULL;
        }

        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->next = minNode;
            tail = tail->next;
        }
    }

    return head;
}
