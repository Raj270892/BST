#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct bstNode
{
	int data;
	int count;
	bstNode *left;
	bstNode *right;
};
bstNode *createbstNode(int data)
{
	bstNode* root=new bstNode();
	root->data=data;
	root->left=root->right=NULL;
	return root;
}
bstNode * insertbstNode(int data,bstNode *root)
{
	if(root==NULL)
	{
		root=createbstNode(data);
	}
	else if (data == root->data)
	{
		(root->count)++;
	}	

	else if(data > root->data)
	{
		root->right= insertbstNode(data,root->right);
	}
	else if(data <=root->data)
	{
		root->left= insertbstNode(data,root->left);
	}
	return root;
}

int depthsearch(bstNode *node)
{
	if (node==NULL) 
		return -1;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = depthsearch(node->left);
		int rDepth = depthsearch(node->right);

		/* use the larger one */
		if (lDepth > rDepth) 
			return(lDepth+1);
		else
			return(rDepth+1);
	}

}

int fulldepthsearch(bstNode *node)
{
	if (node==NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = fulldepthsearch(node->left);
		int rDepth = fulldepthsearch(node->right);

		/* use the larger one */
	
			return(rDepth+lDepth+depthsearch(node));
	}
}

/*
 * Complete the function below.
 */
vector<int> heightAndTotalHeight(vector<int> arr) {
    // Write your code here.
    vector <int> result(2);
    bstNode *root=NULL;
    for(int i=0;i<arr.size();i++)
    {
    	root=insertbstNode(arr[i],root);
    }
    
    int depth,l_node_depth,r_node_depth;
    
   result[0]=depthsearch(root);
   
   result[1]=fulldepthsearch(root);
   
    return result;


}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_size;
    cin >> arr_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_str_temp;
    getline(cin, arr_str_temp);

    vector<string> arr_str = split_string(arr_str_temp);

    vector<int> arr(arr_size);
    for (int arr_i = 0; arr_i < arr_size; arr_i++) {
        int arr_item = stoi(arr_str[arr_i]);

        arr[arr_i] = arr_item;
    }

    vector<int> result = heightAndTotalHeight(arr);


    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

