#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox = {4.5, 3.2, 5.8};
    struct Box *boxPtr = &myBox;

    
    double volume1 = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    double surfaceArea1 = 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);

   
    double volume2 = boxPtr->length * boxPtr->width * boxPtr->height;
    double surfaceArea2 = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);

    printf("Box Dimensions: %.2f x %.2f x %.2f\n", myBox.length, myBox.width, myBox.height);
    printf("Volume (Using asterisk and dot operator): %.2f\n", volume1);
    printf("Surface Area (Using asterisk and dot operator): %.2f\n", surfaceArea1);
    printf("Volume (Using arrow operator): %.2f\n", volume2);
    printf("Surface Area (Using arrow operator): %.2f\n", surfaceArea2);

    return 0;
}
