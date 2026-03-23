#include <bits/stdc++.h>
using namespace std;

// Node structure for the Huffman tree
struct MinHNode {
    char item;               // Character stored in this node
    unsigned freq;           // Frequency of the character
    MinHNode *left, *right;  // Left and right child pointers

    // Constructor for leaf or internal node
    MinHNode(char item, unsigned freq) : item(item), freq(freq), left(nullptr), right(nullptr) {}
};


// Comparator for priority queue (min-heap) based on frequency
struct compare {
    bool operator()(MinHNode *l, MinHNode *r) {
        return l->freq > r->freq; // min-heap: node with lower freq has higher priority
    }
};


// Recursive function to build the Huffman code map (character to binary string)
void buildCodeMap(MinHNode *root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return; // Base case: null node

    // If it's a leaf node (not a special '$' internal node), store the code
    if (root->item != '$')
        huffmanCode[root->item] = str;

    // Traverse left with added '0' to code
    buildCodeMap(root->left, str + "0", huffmanCode);

    // Traverse right with added '1' to code
    buildCodeMap(root->right, str + "1", huffmanCode);
}



// Main function to build Huffman Tree and encode input string
void HuffmanFromString(const string &text) {
    unordered_map<char, int> freq; // Frequency map for each character

    // Step 1: Count frequency of each character in input text
    for (char c : text)
        freq[c]++;

    // Step 2: Create a priority queue (min-heap) of initial leaf nodes
    priority_queue<MinHNode *, vector<MinHNode *>, compare> minHeap;
    for (auto pair : freq)
        minHeap.push(new MinHNode(pair.first, pair.second));

    cout << "Step-by-step construction of Huffman Tree:\n";
    int step = 1;

    // Step 3: Iterate until only one node remains in the heap (the root)
    while (minHeap.size() != 1) {
        // Remove the two nodes with the lowest frequency
        MinHNode *left = minHeap.top(); minHeap.pop();
        MinHNode *right = minHeap.top(); minHeap.pop();

        // Display step details
        string l_item = (left->item == '$') ? "*" : string(1, left->item);
        string r_item = (right->item == '$') ? "*" : string(1, right->item);
        cout << "Step " << step++ << ": Combine "
             << l_item << "(" << left->freq << ") + "
             << r_item << "(" << right->freq << ") = "
             << left->freq + right->freq << "\n";

        // Create a new internal node with combined frequency
        MinHNode *top = new MinHNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Push the combined node back into the heap
        minHeap.push(top);
    }


    // Step 4: Extract the root of the Huffman tree
    MinHNode *root = minHeap.top();


    // Step 5: Generate the Huffman codes using the tree
    unordered_map<char, string> huffmanCode;
    buildCodeMap(root, "", huffmanCode);


    // Display Huffman coding table
    cout << "\nCharacter | Frequency | Code   | Size\n";
    cout << "----------------------------------------\n";
    int compressedBits = 0; // Total size of compressed data in bits

    // For each character, display frequency, Huffman code, and total bits used
    for (auto pair : freq) {
        char ch = pair.first;
        int f = pair.second;
        string code = huffmanCode[ch];
        int bits = f * code.length(); // total bits = freq * length of code
        compressedBits += bits;

        // Display row in coding table
        cout << "   " << left << setw(7) << ch
             << "|   " << left << setw(8) << f
             << "| " << left << setw(6) << code
             << "| " << f << " x " << code.length()
             << " = " << bits << "\n";
    }



    // Step 6: Encode the original input string using the Huffman codes
    string encoded = "";
    for (char c : text)
        encoded += huffmanCode[c]; // Replace each char with its binary code

    // Calculate sizes for comparison
    int uncompressedSize = text.length() * 8; // 8 bits per character
    int treeSizeEstimate = freq.size() * 8;   // Estimate: 8 bits per character in the table



    // Display size comparison and final results
    cout << "\nOriginal String: " << text << "\n";
    cout << "Encoded Binary : " << encoded << "\n\n";

    cout << "Uncompressed Size : " << text.length() << " x 8 = " << uncompressedSize << " bits\n";
    cout << "Frequency Table   : " << freq.size() << " x 8 = " << treeSizeEstimate << " bits\n";
    cout << "Compressed Data   : " << compressedBits << " bits\n";
    cout << "Final Transmission Size = "
         << treeSizeEstimate << " + " << text.length() << " + "
         << compressedBits << " = "
         << (treeSizeEstimate + text.length() + compressedBits) << " bits\n";
}



// Entry point
int main() {
    string input = "BBCCAAAADDDCCCCAAAABBBBCCCCDDDDAAACCCCBBAADDDCCACACAC";
    HuffmanFromString(input);

    return 0;
}
