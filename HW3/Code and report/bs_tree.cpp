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
        
    delete T_nil;

} 

void bs_tree::insert(int key, bs_tree_i_info& t_info)
{
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
    }
    z->p = y;
    if(y == T_nil)
        T_root = z;
    else{
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    
    

}

int bs_tree::convert2(bs_tree_node* x, int* arr, int n){
    if(x == T_nil){
        return n;
    }
    n = convert2(x->left, arr, n);
    arr[n]= x->key;
    n++;
    n= convert2(x->right, arr, n);
    return n;
}
// question 2
int bs_tree::convert(int* array, int n)
{
  //return n;
    return convert2(T_root, array, 0);
}

