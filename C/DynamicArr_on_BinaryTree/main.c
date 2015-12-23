#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"NodeQueue.h"

void Log(Item data){
	printf("%d",data);
}

void print(char *s){
	printf("%s",s);
}

/*
void main(){
	
    BinaryTree * binaryTree=NULL;
	Node * e=NULL;
	BinaryTree * temp_tree=NULL;
	Item rootValue;

	
	//��ʾ��Ϣ
	print("please enter your binaryTree");
	newLine();
	
	//����һ�ö�����������ɳ�ʼ��
	//��ʼ���ڴ������������
	binaryTree=CreateBiTree();	

	rootValue=binaryTree->data;
	
	//������������������Ƿ�Ϊ��
	if(BiTreeEmpty(binaryTree)){
		print("This tree isn't empty");
		newLine();
	}else{
		print("This tree is empty");
	}
	
	//�鿴�ö������Ĳ���
	print("The depth of this tree is : ");
	Log(BiTreeDepth(binaryTree));
	newLine();
	
	//�ö������ĸ��ֱ���
	//�ȸ�����
	print("PreOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	newLine();
	
	//�и�����
	print("InOrderTraverse is ");
	InOrderTraverse(binaryTree,Log);
	newLine();

	//�������
	print("PostOrderTraverse is ");
	PostOrderTraverse(binaryTree,Log);
	newLine();

	//�������
	print("LevelOrderTraverse is ");
	LevelOrderTraverse(binaryTree,Log);
	newLine();
	
	//��ʾĳ���ڵ�����Ӻ��Һ��ӣ�˫�׽ڵ㣬�Ը��ڵ������Ϊ���Խ��
	
	print("The rChild and lChild of the lChild of root are ");
	newLine();
	if(LeftChild(binaryTree,binaryTree->lChild)){
		print("data of lChild is ");
		Log(LeftChild(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No lChild of this Node");
	}
	newLine();
	
	if(RightChild(binaryTree,binaryTree->lChild)){
		print("data of rChild is ");
		Log(RightChild(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No rChild of this Node");
	}
	newLine();

	print("The parent of the lChild of root are ");
	newLine();
	if(Parent(binaryTree,binaryTree->lChild)){
		print("data of parent is ");
		Log(Parent(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No lChild of this Node");
	}

	newLine();
	//��ʾĳ���ڵ�����ֵܣ��Ը��ڵ������Ϊʾ��
	if(RightSibling(binaryTree,binaryTree->lChild)){
		print("data of RightSibling of lChild is ");
		Log(RightSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No RightSibling of this Node");
	}

	newLine();
	//��ʾĳ���ڵ�����ֵܣ��Ը��ڵ���Һ���Ϊʾ��
	if(LeftSibling(binaryTree,binaryTree->lChild)){
		print("data of LeftSibling of rChild is ");
		Log(LeftSibling(binaryTree,binaryTree->lChild)->data);
	}else{
		printf("No LeftSibling of this Node");
	}	

	newLine();
	//����½�㣬����Ͳ���������������
	print("enter the data of your new Node : ");
	e=CreateNode();
	temp_tree=binaryTree;
	while(temp_tree->lChild){
		temp_tree=temp_tree->lChild;
	}
	InsertChild(binaryTree,temp_tree,0,e);
	print("After function InsertChild(lChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	//����½�㣬����Ͳ������������Һ���
	print("enter the data of your new Node : ");
	e=CreateNode();
	InsertChild(binaryTree,temp_tree,1,e);
	print("After function InsertChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	newLine();
	
	//ɾ����㣬ɾ��������
	DeleteChild(binaryTree,Parent(binaryTree,e),0);
	print("After function DeleteChild(lChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	
	DeleteChild(binaryTree,Parent(binaryTree,e),1);
	print("After function DeleteChild(rChild) PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);
	
	newLine();
	//����ĳ���ڵ��ֵ��Ϊ�˷���չʾ�������ڵ�����ȫ����1
	scanAndchangeBiTree(binaryTree,Assign);
	//���ĺ�������ȸ�����
	print("After function Assign PostOrderTraverse is ");
	PreOrderTraverse(binaryTree,Log);

	
	newLine();
	//���ٸ���
	DestroyBiTree(binaryTree);
	if(binaryTree->data!=rootValue){
		printf("this binaryTree has been destroyed");
	}
}
*/

typedef struct {
    BinaryTree * treeRoot;
    int treeDepth;
} T_DYNAMIC_ARR, *PT_DYNAMIC_ARR;

/* ������̬���� */
PT_DYNAMIC_ARR GetDynamicArr()
{
    PT_DYNAMIC_ARR ptDynamicArr = NULL;

    ptDynamicArr = malloc(sizeof(T_DYNAMIC_ARR));
    if ( !ptDynamicArr )
    {
        return NULL;
    }

    memset(ptDynamicArr, 0, sizeof(T_DYNAMIC_ARR));
    ptDynamicArr->treeRoot = InitBiTree();
    if ( !ptDynamicArr->treeRoot )
    {
        free(ptDynamicArr);
        return NULL;
    }

    ptDynamicArr->treeDepth = 1;

    ptDynamicArr->treeRoot->data = 0; 
    
    return ptDynamicArr;
}


void FreeDynamicArr(PT_DYNAMIC_ARR *pptDynamicArr)
{
	PT_DYNAMIC_ARR ptDynamicArr = *pptDynamicArr;
	
    DestroyBiTree( ptDynamicArr->treeRoot );

    free(ptDynamicArr);

    *pptDynamicArr = NULL;
}

/* create a full complete binary tree by depth */
BinaryTree* createFullCompleteBTree_ByDepth( int depth )
{
    BinaryTree * treeRoot = NULL;

    if ( depth <=0 )
    {
        return NULL;
    }

    if ( depth == 1 )
    {
        return InitBiTree();
    }
    else
    {
        treeRoot = InitBiTree();
        if ( ! treeRoot )
        {
            return NULL;
        }

        treeRoot->lChild = createFullCompleteBTree_ByDepth(depth-1);
        treeRoot->rChild = createFullCompleteBTree_ByDepth(depth-1);
    }
}

/* enlarge full complete tree by one depth, left tree leaves is same as orignal */
void enlargeOneDepth_OnfullCompleteTree(PT_DYNAMIC_ARR ptDynamicArr)
{
    BinaryTree* leftTree = ptDynamicArr->treeRoot;
    BinaryTree* rightTree = NULL;
    int depth = ptDynamicArr->treeDepth;

    rightTree = createFullCompleteBTree_ByDepth(depth);
    if ( ! rightTree )
    {
        return;
    }

    ptDynamicArr->treeRoot = InitBiTree();
    if ( ! ptDynamicArr->treeRoot )
    {
        ptDynamicArr->treeRoot = leftTree;
        return ;
    }

    ptDynamicArr->treeRoot->lChild = leftTree;
    ptDynamicArr->treeRoot->rChild = rightTree;

    ptDynamicArr->treeDepth++;
}

/* search tree leaf by path */
BinaryTree* SearchTreeLeafByPath(BinaryTree* ptTreeRoot, int depth,  int path )
{
    int mask_for_first_step = 0;
    int first_step = 0;

    if ( depth == 1 )
    {
        return ptTreeRoot;
    }
    else
    {
        mask_for_first_step = 0x1 << (depth -2);
        first_step = path & mask_for_first_step;

        if ( first_step == 0 )
        {
            ptTreeRoot = ptTreeRoot->lChild;
        }
        else
        {
            ptTreeRoot = ptTreeRoot->rChild;
        }

        depth--;
        
        return SearchTreeLeafByPath(ptTreeRoot, depth-1, path);
    }
}

/* find the tree node(leaf) according to index */
BinaryTree* GetTreeNodeByIndex(PT_DYNAMIC_ARR ptDynamicArr, int index)
{
    BinaryTree* ptTreeLeaf = NULL;

    BinaryTree* ptTreeRoot = ptDynamicArr->treeRoot;
    int depth = ptDynamicArr->treeDepth;

    /*  
    if tree depth is 2, ie, two tiers: 
        root
        /   \
       /     \
    leaf1   leaf2
    then index can be 0 or 1
        0 - leaf1
        1 - leaf2
   the path shall be  0 or 1.
    
    if depth is 3, the path can be
        index 0 - path 00
        index 1 - path 01
        index 2 - path 10
        index 3 - path 11
        
    if tree depth is 1, ie root is leaf
    path is null
    */
    int path = index; 

    ptTreeLeaf = SearchTreeLeafByPath( ptTreeRoot, depth,  path );

    return ptTreeLeaf;
}

/* set value in dynamic array */
void SetValue_DynamicArr(PT_DYNAMIC_ARR ptDynamicArr, int index, int value)
{
    int capacity = pow(2, (ptDynamicArr->treeDepth-1));
    printf("SetValue_DynamicArr capacity(%d) ptDynamicArr->treeDepth(%d)  \r\n", capacity, ptDynamicArr->treeDepth);
    // arr index = [0, capacity-1]
    int maxIndex = capacity - 1;
    int depthGain = 0;
    BinaryTree * ptTreeNode = NULL;

    printf("SetValue_DynamicArr begin enlarge  \r\n");
    // if index overlow, then deepen the tree, tree is full complete binary tree
    if ( index > maxIndex )
    {
    	printf("SetValue_DynamicArr index(%d) maxIndex(%d)  \r\n", index, maxIndex);
    	
        // calculate the depth that need to be increased
         do {
            capacity = capacity * 2;
            maxIndex = capacity -1;
            depthGain++;
         } while( index > maxIndex );
         
         printf("SetValue_DynamicArr depthGain(%d) \r\n", depthGain); 
         
         // deepen the tree
         while( depthGain > 0 )
         {
            enlargeOneDepth_OnfullCompleteTree(ptDynamicArr);
            depthGain--;
         }
    }

    printf("SetValue_DynamicArr begin get tree node  \r\n");
    ptTreeNode = GetTreeNodeByIndex(ptDynamicArr, index);
    if ( ! ptTreeNode )
    {
        return;
    }
    
    ptTreeNode->data = value;
}

int GetValue_DynamicArr(PT_DYNAMIC_ARR ptDynamicArr, int index)
{
    BinaryTree* ptTreeLeaf = NULL;

    ptTreeLeaf = GetTreeNodeByIndex(ptDynamicArr, index);
    if ( !ptTreeLeaf )
    {
        return 0;
    }

    return ptTreeLeaf->data;
}

void main(void)
{
    PT_DYNAMIC_ARR ptDynamicArr = GetDynamicArr();

    printf(" setvale of dynamic arr index(%d) value(%d) \r\n", 3, 10);
    SetValue_DynamicArr(ptDynamicArr, 3, 10);

    printf("--------------- \r\n");
    
    printf("--------------- \r\n");

    int value = GetValue_DynamicArr(ptDynamicArr, 3);
    printf(" getvalue of dynamic arr index(%d), value(%d)  \r\n", 3, value);

    FreeDynamicArr(&ptDynamicArr);
}

