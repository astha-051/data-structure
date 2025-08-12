#include<stdio.h>
#include<string.h>

struct stores{
    char name[20];
    float price;
    int qantity;
};

void update(struct stores *product,float p,int q)  //takes a pointer to a  store structure product
{
    product -> price+=p;  //adding new price
    product -> qantity+=q;
}
float mul(struct stores *stock)
{
    return (stock -> price * stock -> qantity);
}

void main()
{
    float p_increment,value;
    int q_increment;

    struct stores iteam ={"xyz",25.75,12};
    struct stores *ptr = &iteam;  //give array as a pointer

    printf("enter a price which you want to increment and also add another quantity for it:");
    scanf("%f %d",&p_increment,&q_increment);

    update(&iteam,p_increment,q_increment);

    printf("updated values:");
    printf("name=%s \n ",ptr -> name);
    printf("price=%f \n",ptr -> price);
    printf("quantity=%d \n",ptr -> qantity);

    value=mul(&iteam);  //stores the value of total stock

    printf("total value=%f  \n",value);
}