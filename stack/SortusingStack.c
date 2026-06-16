while(top1 != -1){
    int temp = pop1();
    while(!isEmpty() && peek2()>temp){
        push1(pop2());
    }

    push2(temp);
    
}