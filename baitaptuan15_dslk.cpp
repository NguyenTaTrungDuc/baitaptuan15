#include <iostream>
#include <string>

using namespace std;

const int V = 11;

string nodes[V] = {
    "Ha Noi", "Son Tay", "Hoa Binh", "Phu Ly", 
    "Hung Yen", "Hai Duong", "Hai Phong", "Bac Ninh", 
    "Thai Nguyen", "Bac Giang", "Uong Bi"
};

struct Node {
    int desti;
    Node* next;
};

// Ham them canh vao danh sach lien ket
void Add(Node* List[], int u, int v) {
    Node* newNode1 = new Node;
    newNode1->desti = v;
    newNode1->next = List[u];
    List[u] = newNode1;

    Node* newNode2 = new Node;
    newNode2->desti = u;
    newNode2->next = List[v];
    List[v] = newNode2;
}

// Duyet BFS
void bfs_List(Node* List[], int start) {
    bool visited[V] = {false};
    int queue[100];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        cout << nodes[u];

        Node* temp = List[u];
        while (temp != NULL) {
            int v = temp->desti;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
        
        if (front < rear) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Node* List[V];
    for (int i = 0; i < V; i++) {
        List[i] = NULL;
    }

    // Khoi tao danh sach cac canh
    int edges[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {0, 5}, {0, 7}, {0, 8}, 
        {3, 4}, {4, 5}, {5, 6}, {7, 9}, {7, 10}, {9, 10}, {10, 6}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    // Them canh vao danh sach lien ket
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        Add(List, u, v);
    }

    cout << "BFS VOI DANH SACH LIEN KET (Bat dau tu Ha Noi)" << endl;
    bfs_List(List, 0);

    return 0;
}
