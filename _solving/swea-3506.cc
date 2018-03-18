#include <cstdio>
using namespace std;
using LL = long long;

struct Rt {
	struct Nd {
		LL key, count;
		Rt *left, *right;
	};
	Nd *root = nullptr;
	int height = 0;

	void insert(LL key) {
		if(root == nullptr) {
			root = new Nd {key, 1, new Rt(), new Rt()};
			height = 1;
			return;
		}

		if(key > root->key) { ++root->count; root->right->insert(key); }
		else if(key < root->key) { root->left->insert(key); }
		else { ++root->count; return; }

		rebal(getBal());
	}

	LL find(LL key) {
		LL ret;
		if(root == nullptr) ret = 0;
		else if(key > root->key) ret = root->right->find(key);
		else {
			ret = root->count;
			if(key < root->key) ret += root->left->find(key);
		}
		return ret;
	}

	int getBal() {
		int lh = root->left->height, rh = root->right->height;
		height = 1+(lh>rh?lh:rh);
		return rh-lh;
	}

	void rebal(int bal) {
		if(bal < -1) {
			if(root->left->getBal() > 0) root->left->lrot();
			rrot();
		}
		else if(bal > 1) {
			if(root->right->getBal() < 0) root->right->rrot();
			lrot();
		}
	}

	void lrot() {
		auto A = root->right->root;
		auto B = A->left;
		*root->right = *B;
		root->count = root->count - A->count;
		B->root = root;
		root = A;
		root->left->getBal();
		getBal();
	}

	void rrot() {
		auto A = root->left->root;
		auto B = A->right;
		*root->left = *B;
		A->count = A->count + root->count;
		B->root = root;
		root = A;
		root->right->getBal();
		getBal();
	}

	~Rt() {
		if(root != nullptr) {
			delete root->left;
			delete root->right;
			delete root;
		}
	}
};

LL solve() {
	int N, P;
	scanf("%d %d", &N, &P);
	LL offset = 0, answ = 0;
	Rt tree;
	for(int i=0; i<N; ++i) {
		int s;
		scanf("%d", &s);
		s -= P;
		tree.insert(-offset);
		offset += s;
		answ += tree.find(-offset);
	}
	return answ;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		printf("#%d %lld\n", t, solve());
	}
	return 0;
}