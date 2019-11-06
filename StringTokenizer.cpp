#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

struct TokenFreq {
    string token;
    int freq{1};
};

// part one
void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols);
void printVec( vector<vector<int>> const& matrix);
void printVec(vector<string> vec);
void printVec(vector<TokenFreq> vec);
void addValues( vector<vector<int>> &matrix, int numRows, int numCols);
// part two
void getTokenFreqVec(const string &istr, vector<TokenFreq> &tfVec);

bool operator <=(const TokenFreq &o1, const TokenFreq &o2);
TokenFreq operator+(const TokenFreq &o1, const TokenFreq &o2);

void swap(TokenFreq& a, TokenFreq& b);
void selectionSort( vector<TokenFreq> & tokFreqVector);





int main() {

    string s = "No one wants to die. Even people who want to go to heaven don’t want to die to get there. And yet death is the destination we all share. No one has ever escaped it. And that is as it should be, because Death is very likely the single best invention of Life. It is Life’s change agent. It clears out the old to make way for the new. Right now the new is you, but someday not too long from now, you will gradually become the old and be cleared away. Sorry to be so dramatic, but it is quite true. Your time is limited, so don’t waste it living someone else’s life. Don’t be trapped by dogma — which is living with the results of other people’s thinking. Don’t let    the noise of others’ opinions drown out your own inner voice. And most important, have the courage to follow your heart and intuition. They somehow already know what you truly want to become. Everything else is secondary. When I was young, there was an amazing publication called The Whole Earth Catalog, which was one of the bibles of my generation. It was created by a fellow named Stewart Brand not far from here in Menlo Park, and he brought it to life with his poetic touch. This was in the late 1960s, before personal computers and desktop publishing, so it was all made with typewriters, scissors and Polaroid cameras. It was sort of like Google in paperback form, 35 years before Google came along: It was idealistic, and overflowing with neat tools and great notions.Stewart and his team put out several issues of The Whole Earth Catalog, and then when it had run its course,     they put out a final issue. It was the mid-1970s, and I was your age. On the back cover of their final issue was a photograph of an early morning country road, the kind you might find yourself hitchhiking on if you were so adventurous. Beneath it were the words: “Stay Hungry. Stay   Foolish.” It was their farewell message as they signed off. Stay Hungry. Stay Foolish. And I have always wished that for myself. And now, as you graduate to begin anew, I wish that for you.Stay Hungry. Stay Foolish.";
    cout << s << endl;
    vector<TokenFreq> tokens;
    getTokenFreqVec(s, tokens);
    printVec(tokens);
    cout << endl;
    
    selectionSort(tokens);
    printVec(tokens);

    
    
    
    return 0;
}


void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols) {
    int fillVal = 0;
    
    vector< vector<int> > temp(numRows, vector<int>(numCols, fillVal));
    
    for (int i{0}; i < numRows; i++)
        for (int j{0}; j < numCols; j++)
            temp[i][j] = i*j;
            
    cout << "size of matrix is: " << numRows << "x" << numCols << endl;
    for(int i{0}; i < numRows; i++)
        for (int j{0}; j < numCols; j++)
            cout << "matrix[" << i << "][" << j << "]=" << temp[i][j] << endl;
    
    matrix = temp;
}

void printVec( vector<vector<int>> const& matrix ) {
    for ( auto row: matrix ) {
        for ( auto val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void printVec( vector<string> vec) {
    for (auto c: vec)
        cout << c << endl;
}

void printVec( vector<TokenFreq> vec) {
    cout << "size=" << vec.size() << "{ " << endl;
    for (int i{0}; i < vec.size(); i++) {
        cout << "[" << i << "] = (token = " << vec[i].token << ", freq = " << vec[i].freq << ")" << endl;
    }
}

void addValues( vector<vector<int>> &matrix, int numRows, int numCols) {
    
    for (int i{0}; i < numRows; ++i) {
        for (int j{0}; j < numCols; ++j ) {
            cout << "Enter value for Matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void getTokenFreqVec(const string &istr, vector<TokenFreq> &tfVec) {
    string value;
    TokenFreq temp;
    istringstream iss(istr);
    while(getline(iss, value, ' ')) { 
    transform(value.begin(), value.end(), value.begin(), ::tolower);
    
    int flag = 1;
    
    for(int i{0}; i < tfVec.size(); i++) { 
    if(tfVec[i].token == value){
    tfVec[i].freq += 1; 
    flag = 0;
        }
    }
    
    if(flag) { 
        temp.token = value;
        tfVec.push_back(temp);
        }
    }
}




bool operator <=(const TokenFreq &o1, const TokenFreq &o2) {
    int comp1;
    int comp2;
    comp1 = o1.freq;
    comp2 = o2.freq;
    
    if (comp1 <= comp2)
        return true;
    else false;
}

TokenFreq operator+(const TokenFreq &o1, const TokenFreq &o2) {

    string stringOr = " or ";
    TokenFreq temp;
    temp.token = o1.token + stringOr + o2.token;
    temp.freq = o1.freq + o2.freq;
    return temp;
}

void swap(TokenFreq& a, TokenFreq& b) {
    TokenFreq temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort( vector<TokenFreq> & tokFreqVector) {
    int i, j, minIndex;
    TokenFreq temp;
    
    for (i = 0; i < tokFreqVector.size() - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < tokFreqVector.size(); j++)
            if (tokFreqVector[j].freq <= tokFreqVector[minIndex].freq)
                minIndex = j;
        if (minIndex != i) {
            temp = tokFreqVector[i];
            tokFreqVector[i] = tokFreqVector[minIndex];
            tokFreqVector[minIndex] = temp;
        }
    }
}


