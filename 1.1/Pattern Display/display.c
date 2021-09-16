#include<stdio.h>

int main(){

    int prompt, option;

    // Welcome Message
    printf("#####  Welcome  #####\n\nPlease choose an option:\n");

    for(; ;){

        //Main Option Prompt

        printf("\n$$ If you want to continue enter 1 or enter 2 for quit $$\n");
        scanf("%d", &prompt);

            if ( prompt == 2){
                printf("\n#####  Thank You  #####\n");
                break;

            } else if (prompt == 1){

                // Option Prompt

                printf("\n1.Pyramids\n2.Hollow Diamonds\n3.Penguins\n4.Odd X\n5.Draw Patterns\n\n");
                printf("Enter your option number:");
                scanf("%d", &option);

                if(option == 1){

                    //    Part: A (1)

                    int row,col, input ;

                    printf("\nEnter an input number:");
                    scanf("%d", &input);

                    for (row = 1; row <= input ; row++){
                            for(col = 1 ; col <= input-row ; col++){
                                printf(" ");
                            }
                             for(col = 1; col <= row ; col++ ){
                                    printf("*");
                            }
                        printf("\n");
                    }

                    printf("\n\n");

                    //Part: A (2)

                    for (row = 1; row <= input; row++){
                            for (col = 1 ; col <= input - row; col++){
                                printf(" ");
                            }
                            for (col = 1; col<= 2*row-1; col++){
                                printf("*");
                            }
                        printf("\n");
                    }

                }else if (option == 2){

                    //    Part : B

                    int input, row, col, k;

                    printf("\nEnter an input number:");
                    scanf("%d", &input);

                    for(row = 1; row <= input; row++){
                            for(col = 1; col <= input; col++){
                                if(row+col == input+1){
                                    printf("*");
                                }else{
                                    printf(" ");
                                }
                            }
                            for(col = input-1; col >= 1; col--){
                                if(row+col == input+1){
                                    printf("*");
                                }else{
                                    printf(" ");
                                }
                            }
                        printf("\n");
                    }
                    for(row = input-1; row >= 1; row--){
                            for(col = 1; col <= input; col++){
                                if(row+col == input+1){
                                    printf("*");
                                }else{
                                    printf(" ");
                                }
                            }
                            for(col = input-1; col >= 1; col--){
                                if(row+col == input+1){
                                    printf("*");
                                }else{
                                    printf(" ");
                                }
                            }
                        printf("\n");
                    }
                }else if(option == 3){

                    //    Part: C

                    int input, i, j;

                    printf("\nEnter an input number:");
                    scanf("%d", &input);

                    for (i = 1; i <2; i++){
                        for(j = 1; j<= input; j++ ){
                            printf("<O  ");
                        }
                        printf("\n");
                        for(j = 1; j<= input; j++ ){
                            printf("_()_");
                        }
                    }
                }else if (option == 4){

                    //    Part : D

                    int input, row, col;

                    printf("\nEnter an input number:");
                    scanf("%d", &input);

                    for (row = 1; row <= input; row++){
                            for(col = 1; col <= input; col++){
                                if(row == col || row+col == input+1){
                                    printf("*");
                                }else{
                                    printf(" ");
                                }
                            }
                        printf("\n");
                    }

                }else if (option ==5){

                    //    Part: E

                    int input, row, col;

                    printf("\nEnter an input number:");
                    scanf("%d", &input);

                    for( row = 1; row <= input; row++){
                        for(col = 1; col<= row; col++){
                            printf("*");
                        }
                        for(col = 1; col <= input-row; col++){
                            printf(" ");
                        }
                    }

                }else{
                    printf("\nInvalid option, Please choose right one\n");
                }
            }else{
                printf("\nInvalid option,Please choose right one\n");
            }

    }

    return 0;
}
