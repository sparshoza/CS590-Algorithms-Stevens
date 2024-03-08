#include "bs_tree.h"
#include <list>
#include <iostream>

using namespace std;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{
/*
 create T_nil element copied from rb tree
 */
    T_nil = new bs_tree_node();
    T_nil->p = T_nil;
    T_nil->left = T_nil;
    T_nil->right = T_nil;
    
    //root of bs tree
    T_root = T_nil;
} 

bs_tree::~bs_tree()
{
    //delete nil element and all allocated nodes copied from rb tree file
    
    remove_all(T_root);
    
    delete T_nil;

} 

void bs_tree::insert(int key, bs_tree_i_info& t_info)
{
    //current node = x
    //previous node = y
    // new insertNode = z
    bs_tree_node* x;
    bs_tree_node* y;
    
    bs_tree_node* z = new bs_tree_node;
    z->key= key;
    z->left= T_nil;
    z->right = T_nil;
    z->p = T_nil;
    
    y= T_nil;
    x= T_root;
    
    //similar code as rb tree
    
    while(x != T_nil){
        y = x;
        if (z->key == x->key){
            t_info.i_duplicate++;
            
            delete z;
            return ;
        }
        //insertion path ways for left and right
        if(z->key < x->key){
            x= x->left;
        }
        else if(z->key > x->key){
            x= x->right;
        }
//else{
            //count for duplicate
//            t_info.i_duplicate++;
            //deletes address from heap memory
//            delete z;
            //no duplicates are shown twice
//            return;
//        }
    }
    //block sets all the pointers after while loop figures out where it goes
    z->p = y;
    if(y == T_nil)
        //if there is no tree yet, this establishes the root
        T_root = z;
    else{
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    
    

}

//add helper function for convert to do traversal of tree
int bs_tree::convert_traversal(bs_tree_node* x, int* arr, int n){
    if(x == T_nil){
        //check if we are on the leaf node
        return n;
    }
    n = convert_traversal(x->left, arr, n);
    //insert current node key
    arr[n]= x->key;
    n++;
    n= convert_traversal(x->right, arr, n);
    return n;
}

// TODO: modified inorder tree walk method to save the 
// sorted numbers in the first argument: int* array.
// question 2
int bs_tree::convert(int* array, int n)
{
  //return n;
    return convert_traversal(T_root, array, 0);
}

//added remove all function
void bs_tree::remove_all(bs_tree_node* x){
//removes all tree elements copied from rb_tree
  if (x != T_nil)
    {
      remove_all(x->left);
      remove_all(x->right);
    //node is no longer needed
      delete x;
    }
}
