#include <iostream>

using namespace std;

//����������ṹ 
struct Node {
    int val;
    Node* left;
    Node* right;

	// ��ʼ���ڵ�Ĺ��캯��
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// ����˫�׽������
int countParentNodes(Node* root) {
	// ���������Ϊ�գ��򷵻�0
    if (!root) {
        return 0;
    }

    int count = 0;

	// �������������������Ϊ�գ����������ĸ��ڵ���һ��˫�׽ڵ�
	if (root->left) {
	    count++;
	}
	
	// �������������������Ϊ�գ����������ĸ��ڵ���һ��˫�׽ڵ�
	if (root->right) {
	    count++;
	}
	
	// �ݹ��������������������˫�׽ڵ��������������Ǽӵ���ǰ�ڵ��˫�׽ڵ�������
	return count + countParentNodes(root->left) + countParentNodes(root->right);
}

// ����Ҷ�ӽ������
int countLeafNodes(Node* root) {
	// ���������Ϊ�գ��򷵻�0
    if (!root) {
        return 0;
    }

	// �����ǰ�ڵ�û������������������������һ��Ҷ�ӽڵ㣬����1
	if (!root->left && !root->right) {
	    return 1;
	}
	
	// �ݹ��������������������Ҷ�ӽڵ��������������Ǽӵ���ǰ�ڵ��Ҷ�ӽڵ�������
	return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// �Ӽ��̶�ȡ������
Node* readBinaryTree() {
    int val;
    cin >> val;

	// �����ǰ�ڵ��ֵΪ-1����ýڵ�Ϊ�սڵ㣬����nullptr
    if (val == -1) {
        return nullptr;
    }

	// ����һ���µĶ������ڵ㣬���ݹ��ȡ��������������
    Node* root = new Node(val);
    root->left = readBinaryTree();
    root->right = readBinaryTree();

    return root;
}

int main() {
	// �Ӽ��̶�ȡ������
	cout << "ÿһ���ڵ�ʹ�ÿո���߻��з��ָ�����-1�����λ�ýڵ�Ϊnull\n�밴�ղ������˳��������ȷ�Ķ��������ݣ�";
    Node* root = readBinaryTree();

	// ����˫�׽��������Ҷ�ӽ����������������
    int parentNodes = countParentNodes(root);
    int leafNodes = countLeafNodes(root);

    cout << "˫�׽��������" << parentNodes << endl;
    cout << "Ҷ�ӽ��������" << leafNodes << endl;

    return 0;
}
