#include "header.h"




string strBuffer;
MinHeapNode* root;


//To allocate new minimum tree node
MinHeapNode* setNode(char d, int freq, MinHeapNode* left, MinHeapNode* right)
{
    MinHeapNode* node = new MinHeapNode();

    node->data = d;
    node->frequency = freq;
    node->left = left;
    node->right = right;

    return node;
}

//Comparison object to be used to order the heap
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        // high priority is low frequency
        return l->frequency > r->frequency;
    }
};

//Traverse the Huffman Tree and store Huffman codes in an unordered map.
void compress(MinHeapNode* root, string data,
              unordered_map<char,string> &huffmanCode)
{
    if (!root)
        return;
    //Leaf node is found
    if (!root->left && !root->right)
    {
        huffmanCode[root->data] = data;
    }
    compress(root->left, data + "0", huffmanCode);
    compress(root->right, data + "1", huffmanCode);
}

//Traverse the Huffman Tree and decode the encoded file
string decompress(MinHeapNode* root, int &index, string file)
{
    string decompressOutput = "";
    //If the root is NULL
    if (!root) {
        return decompressOutput;
    }
    //If leaf node is found
    if (!root->left && !root->right)
    {
        decompressOutput+=root->data; //Store the decoded data in the output
        return decompressOutput;
    }
    index++;

    if (file[index] =='0')
        decompressOutput+=decompress(root->left, index, file);
    else
        decompressOutput+=decompress(root->right, index, file);
}

//Builds Huffman Tree and compress input into string of zeros and ones
void XMLCompress(string data)
{
    strBuffer = "";

    //Count the frequency of each character in the input file and store it in an unordered map
    unordered_map<char, int> dataFreq;
    for (char i: data) {
        dataFreq[i]++;
    }

    //Create a priority queue to store live nodes of Huffman tree
    priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> huffmanHeap;

    //Create a leaf node for each character and add it to the priority queue.
    for (auto pair: dataFreq) {
        huffmanHeap.push(setNode(pair.first, pair.second, nullptr, nullptr));
    }

    //Do till there is more than one node in the queue
    while (huffmanHeap.size() != 1)
    {
        // Remove the two nodes of the highest priority
        // (the lowest frequency) from the queue
        MinHeapNode *l = huffmanHeap.top();
        huffmanHeap.pop();
        MinHeapNode *r = huffmanHeap.top();
        huffmanHeap.pop();

        //Create a new internal node with these two nodes as children and with
        //frequency equal to the sum of the two nodes' frequencies
        //Add the new node to the priority queue.
        int sum = l->frequency + r->frequency;
        huffmanHeap.push(setNode('\0', sum, l, r));
    }

    //Root stores pointer to root of Huffman Tree
    root = huffmanHeap.top();

    //Traverse the Huffman Tree and store Huffman Codes in a map. Also prints them
    unordered_map<char,string> huffman;
    compress(root, "", huffman);
//    cout << "Huffman codes are :\n" << '\n';
//    for (auto pair: huffman)
//    {
//        cout << pair.first << " " << pair.second << '\n';
//    }
    string encodedStr = "";
    //Store the encoded string
    for (char i: data)
    {
        encodedStr += huffman[i];
    }

    strBuffer = encodedStr;
    ofstream file1("Compressed.txt");
    std::string CompresseOutput;
    int counter=0;
    int mask=0;
    unsigned long long remaindData = (data.length() ) % 8;

    for (int i=0; i<data.length()-remaindData; i++){
        mask=mask<<1;
        if (data[i]=='1')
        {
            mask=mask|1;
        }

        counter ++;
        if (counter==8)
        {

            CompresseOutput+=mask; //Store the compressed bits

            mask=0; //Clear the mask
            counter=0; //Clear the counter

        }
    }

    for (int i=data.length()-remaindData;i<data.length();i++){

        CompresseOutput+=data[i];
    }
    for(int i = 0; i < CompresseOutput.size(); i++){
        file1 << CompresseOutput[i];
    }
    file1.close();


}


//Decode the encoded file :)
void XMLDecompress(){

    ofstream file2("Decompressed.txt");
    int index = -1;
    string decompressOutput="";


    //Traverse the Huffman Tree and decode the encoded string
    while (index < (int)strBuffer.size() - 2)
    {
        decompressOutput+=decompress(root, index, strBuffer);
    }
    for(int i = 0; i < decompressOutput.size(); i++){
        file2 << decompressOutput[i];
    }
    file2.close();

    //return decompressOutput;
}
