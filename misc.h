#ifndef ASSIGNMENT_ARRAY_ALGORITHMS_MISC_H
#define ASSIGNMENT_ARRAY_ALGORITHMS_MISC_H
void enterData(int & x, int low, int high, std::string name){
    do{
        std::cout << "Enter " << name << std::endl;
        std::cin >> x;
    }while (x > high || x < low);
}

void enterVector(std::vector<int> & vec){
    int elem=0, numEl;
    enterData(numEl, 0, INT_MAX, "vector length");
    for (int i = 0; i < numEl; i++){
        enterData(elem, INT_MIN, INT_MAX, "next element");
        vec.push_back(elem);
    }
}

void swapValVector(std::vector<int> & vec, int idx1, int idx2){
    int tmp = vec[idx1];
    vec[idx1] = vec[idx2];
    vec[idx2] = tmp;
}
#endif //ASSIGNMENT_ARRAY_ALGORITHMS_MISC_H
