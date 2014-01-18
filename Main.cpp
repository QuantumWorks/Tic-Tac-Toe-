 #include <iostream>

-#include <string>// just in case!

-using namespace std;

 

+using namespace std;

 

 

-//Add more comments so we can see what u did!

 class Table

 {

 private:

   char data[ 9 ];

   

 public:

-  Table()

+  Table()//initializes board

   {

     for ( int i = 0; i < 9; ++i )

     {

@@ -19,46 +17,82 @@ class Table

     }

   }

 

-  void Set( int row, int column, char letter )

+  void Set( int row, int column, char letter )//sets an letter on board

   {

     data[ row * 3 + column ] = letter;

   }

   

-  char Get( int row, int column )

+  char Get( int row, int column )//gets a letter on board

   {

     return data[ row * 3 + column ];

   }

-};

-

-// Draw the bord!

-void DrawBoard( Table table )

-{

-  for ( int r = 0; r < 3; ++r )

+  

+  void Draw()//draws board

   {

-    for ( int c = 0; c < 3; ++c )

+    for ( int r = 0; r < 3; ++r )

     {

-      cout << "|" << table.Get( r, c );

+      for ( int c = 0; c < 3; ++c )

+      {

+        cout << "|" << Get( r, c );

+      }

+      cout << "|" << endl;

+      cout << "_______" << endl;

     }

-    

-    cout << endl;

   }

-}

+};

 

 

-//Main function!

 int main()

 {

-  SetConsoleTitle(TEXT(" Quantum Works Tic Tac Toe "))//Console Title!

-  

   Table table;

   

+  int row, column;

+  

   while ( true )

   {

     DrawBoard();

     

-    MessageBox(NULL, L" player 1's turn ", NULL, NULL); // Popupwindow

+    cout << "player 1's turn( x )" << endl;

+    

+    a:

+    

+    cout << "enter a row & column: ";

+    

+    cin >> row >> column;

+    

+    if ( table.Get( row, column ) != ' ' )

+    {

+      cout << "invalid pick, please choose again." << endl;

+      goto a;

+    }

+    else

+    {

+      table.Set( row, column, 'x' );

+    }

+    

+    //Check for win

+    

+    DrawBoard();

+    

+    cout << "player 2's turn( o )" << endl;

+    

+    b:

+    

+    cout << "enter a row & column: ";

+    

+    cin >> row >> column;

+    

+    if ( table.Get( row, column ) != ' ' )

+    {

+      cout << "invalid pick, please choose again." << endl;

+      goto b;

+    }

+    else

+    {

+      table.Set( row, column, 'o' );

+    }

     

-    //continue...

+    //Check for win

   }

 

   return 0;
