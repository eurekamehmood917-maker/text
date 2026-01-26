/*int tree_insert(tree_node**root,struct stu data)
{
	if(*root==NULL)
		{
			*root=malloc(sizeof(struct tree_node));
			if(*root==NULL)
				return -1;
			(*root)->data=data;
			(*root)->l=NULL;
			(*root)->r=NULL;
			return 0;
		}
	if((*root)->data.id<data.id)
		tree_insert(&(*root)->r,data)
		else
		tree_insert(&(*root)->1,data);
}*/





int struct tree_node(struct tree_node **root,data.id)
{
	if(*root==NULL)
	{*root==malloc(sizeof(struct tree_node))
		if(*root==NULL)
			return -1;
		(*root)->data=data;
		(*root)->r=NULL;
		(*root)->l=NULL;
		return 0;
	}
	if((*root)->data<data)
	tree_insert(&(*root)->r,data);
	tree_insert(&(*root)->l,data);
}

void print(struct stu data)
{
	printf("%d %s %d\n",data.id,data.name,data.math);
}

void tree_display(struct tree_node *root)
{:
	if(root=NULL)
		return;
	tree_display(root->r);
	tree_display(root->l);
}

