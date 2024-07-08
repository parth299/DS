// Create two stacks in one array

class TwoStack{
    public:
        int *arr;
        int size;
        int top1, top2;

    TwoStack(int value) {
        arr = new int[value];
        this->size = value;
        this->top1 = -1;
        this->top2 = value;
    }
}