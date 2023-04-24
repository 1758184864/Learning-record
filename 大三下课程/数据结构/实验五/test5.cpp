#include <iostream>

using namespace std;

// ����������ڵ�
struct TreeNode {
    // �ڵ�ֵ
	int val;
	// ���ӽڵ�
    TreeNode* left;
	// ���ӽڵ� 
    TreeNode* right;
    // ���캯��
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ����������
TreeNode* buildTree() {
    // �������ڵ㣬ֵΪ1
    TreeNode* root = new TreeNode(1);

    // ���������ӽڵ㣬ֵ�ֱ�Ϊ2��3
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // �������ӽڵ�������ӽڵ㣬ֵ�ֱ�Ϊ4��5
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // �������ӽڵ�������ӽڵ㣬ֵ�ֱ�Ϊ6��7
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

	// ���ظ��ڵ�ָ��
    return root;
}

// ǰ�����
void preOrder(TreeNode* root) {
	// ����ڵ�Ϊ�գ�ֱ�ӷ���
    if (root == NULL) return;
    // ����ڵ�ֵ
    cout << root->val << " ";
    // ����������
    preOrder(root->left);
    // ����������
    preOrder(root->right);
}

// �������
void inOrder(TreeNode* root) {
	// ����ڵ�Ϊ�գ�ֱ�ӷ���
    if (root == NULL) return;
    // ����������
    inOrder(root->left);
    // ����ڵ�ֵ
    cout << root->val << " ";
    // ����������
    inOrder(root->right);
}

// �������
void postOrder(TreeNode* root) {
	// ����ڵ�Ϊ�գ�ֱ�ӷ���
    if (root == NULL) return;
    // ����������
    postOrder(root->left);
    // ����������
    postOrder(root->right);
    // ����ڵ�ֵ
    cout << root->val << " ";
}

int main() {
    // ����������
    TreeNode* root = buildTree();

    // ǰ�����
    cout << "ǰ�������";
    preOrder(root);
    cout << endl;

    // �������
    cout << "���������";
    inOrder(root);
    cout << endl;

    // �������
    cout << "���������";
    postOrder(root);
    cout << endl;

    return 0;
}
