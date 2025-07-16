[Home](../README.md#data-structures)

# Binary Trees

<!-- TOC -->

- [Breadth First Traversal](#breadth-first-traversal)
- [Depth First Traversal](#depth-first-traversal)

<!-- /TOC -->

```C++
template <typename T>
class BinaryTree {
	private:
		struct Node {
			T data;
			Node* left = nullptr;
			Node* right = nullptr;
		}

		Node* _root;

	public:
		enum class BreadthFirstType {
			LEFT_RIGHT,
			RIGHT_LEFT
		};
		void breadthFirstTraversal(bool process(T& value), BreadthFirstType type = BreadthFirstType::LEFT_RIGHT);

		enum DepthFirstType {
			IN_ORDER, // left, root, right
			PRE_ORDER, // root, left, right
			POST_ORDER, // left, right, root
			REVERSE_IN_ORDER, // right, root, left
			REVERSE_PRE_ORDER, // root, right, left
			REVERSE_POST_ORDER // right, left, root
		};
		void depthFirstTraversal(bool process(T& value), DepthFirstType type = DepthFirstType::IN_ORDER);
};
```

## [Breadth First Traversal](#binary-trees)
Traversal by level.

```C++
template <typename T>
void BinaryTree<T>::breadthFirstTraversal(bool process(T& value), BreadthFirstType type) {
	Queue q;
	q.push(_root);
	while (!q.isEmpty()) {
		Node* node = q.pop();
		if (!process(node->data)) return;
		switch (type) {
			case BreadthFirstType::LEFT_RIGHT:
				q.push(node->left);
				q.push(node->right);
				break;
			case BreadthFirstType::RIGHT_LEFT:
				q.push(node->right);
				q.push(node->left);
				break;
		}
	}
}
```

## [Depth First Traversal](#binary-trees)
- Needs a visited check before pushing.

```C++
template <typename T>
void BinaryTree<T>::depthFirstTraversal(bool process(T& value), DepthFirstType type = DepthFirstType::IN_ORDER) {
	Stack s;
	s.push(_root);
	while (!s.isEmpty()) {
		Node* node = s.pop();
		if (node->left) {
			s.push(node->left);
			continue;
		}
		if (!process(node->data)) return;
		if (node->right) {
			s.push(node->right);
			continue;
		}
	}
}
```