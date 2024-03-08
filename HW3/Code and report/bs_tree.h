#ifndef __BS_TREE_H__
#define __BS_TREE_H__

struct bs_tree_node 
{
  int		key;
  bs_tree_node*	left;
  bs_tree_node*	right;
  bs_tree_node*	p;
};

struct bs_tree_i_info
{
  int i_duplicate;

  void reset()
    { i_duplicate = 0; }
};


class bs_tree
{ 
  protected:
    bs_tree_node*	T_nil;
    bs_tree_node*	T_root;
    
    //added helper function added in binary search tree cpp
    int convert2(bs_tree_node* x, int* arr, int n);

  public:
    bs_tree();
    ~bs_tree();

    void insert(int, bs_tree_i_info&);
    int convert(int*, int);

   
};
#endif
