#include <iostream>
using namespace std;
struct library_struct
{
   string book_name;
   int book_id;

   library_struct *next;
};
class library_class
{
public:
   library_struct *head;
   int N;
   library_class()
   {
      head = NULL;
      N = 0;
   }
   ~library_class()
   {
      while (head != NULL)
      {
         delete_front();
      }
   }
   library_struct *input_student()
   {
      library_struct *new_node = new library_struct;
      cout << "Enter book name :";
      cin >> new_node->book_name;
      cout << "Enter total books for borrow  :";
      cin >> new_node->book_id;

      return new_node;
   }
   void add_front()
   {
      library_struct *new_node = input_student();

      new_node->next = head;
      head = new_node;
      N++;
      new_node = NULL;
   }
   void delete_front()
   {
      if (head != NULL)
      {
         library_struct *temp = head;
         head = head->next;
         delete temp;
         N--;
         temp = NULL;
      }
      else
      {
         cout << "Linked list is empty :" << endl;
      }
   }
   void push()
   {
      add_front();
   }
   void pop()
   {
      if (head != NULL)
      {
         delete_front();
      }
      else
      {
         cout << "Pop operation can1t perfom bcz linked list is empty " << endl;
      }
   }
   library_struct *top()
   {
      cout << "TOp student name is " << head->book_name << endl;
      cout << "TOp student total books are  " << head->book_id << endl;
      return head;
   }
   bool empty()
   {
      return (N == 0);
   }
   int size()
   {
      return N;
   }
   void dsiplay_student_inserted()
   {
      library_struct *temp = head;

      cout << "\tName \tTotal Books " << endl;
      while (temp != NULL)
      {
         cout << "\t" << temp->book_name << "\t" << temp->book_id << endl;
         temp = temp->next;
      }
   }
};
int main()
{
   library_class obj;
   int choice;
   for (;;)
   {
      cout << "1 show all student record " << endl;
      cout << "2 push  student record " << endl;
      cout << "3 pop  student record " << endl;
      cout << "4 top student  record " << endl;
      cout << "5 total  student record " << endl;
      cout << "6 Exit" << endl;
      cout << "Enter your choice :";
      cin >> choice;
      if (choice == 1)
      {
         obj.dsiplay_student_inserted();
         cout << "All inseted data display successfully " << endl;
      }
      else if (choice == 2)
      {
         obj.push();
         cout << "Push data successfully " << endl;
      }
      else if (choice == 3)
      {
         obj.pop();
         cout << "Pop data successfully " << endl;
      }
      else if (choice == 4)
      {
         obj.top();
         cout << "TOp data display successfully " << endl;
      }
      else if (choice == 5)
      {
         cout << "Total students of libarary are " << obj.size();
      }
      else
      {
         cout << "Invalid choice Enter your choice Again " << endl;
      }
   }
}
