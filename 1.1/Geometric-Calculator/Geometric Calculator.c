#include<stdio.h>

int main(){

    // Welcome Message
    printf("****** Welcome to Geometric Calculator ******\n\n");

    //Main Option Prompt
    int mainOption;
    for(; ;){

        printf("\n**For Calculation enter 1\n***To quit the session enter 2\n");
        scanf("%d", &mainOption);

            if ( mainOption == 2){

                break;

            } else{

                // Option Prompt
                printf("\nAvailable Option:\n");
                printf("1.Triangles\n2.Circles\n3.Quadrilateral\n4.Cube\n5.Cylinder\n\n");

                int option;
                printf("Enter your option number:");
                scanf("%d", &option);

                // Calculator Operation Starts
                if (option == 1){

                    // Triangle(Completed by Saikat:011211036)

                    printf("\nYou have chosen Triangles\n\n");
                    printf("What do you want to calculate ??\n");
                    printf("1.Area of a triangle\n2.Type of triangle based on angle\n3.Type of triangle based on sides\n\n");
                    printf("Choose Your Option:");

                    int triangleOption;
                    scanf("%d", &triangleOption);

                    if (triangleOption == 1){

                        //Area of triangle
                        float triHeight, triBase;
                        printf("Enter height:");
                        scanf("%f", &triHeight);
                        printf("Enter base:");
                        scanf("%f", &triBase);

                        float triangleArea = ( triHeight * triBase)/ 2;
                        printf("Area of triangle is %.2f", triangleArea);

                    }else if (triangleOption == 2){

                        //Type of triangle based on angle
                        float angleOne, angleTwo;
                        printf("Enter two angles:");
                        scanf("%f%f", &angleOne, &angleTwo);

                        if(angleOne + angleTwo >= 180){
                            printf("It is not a triangle\n");
                        }
                        else if(angleOne > 90 || angleTwo > 90 ){
                            printf("Obtuse Angled Triangle\n");
                        }else if(angleOne == 90 || angleTwo == 90 ){
                            printf("Right-Angled Triangle\n");
                        }else{
                            printf("Acute Angled Triangle\n");
                        }

                    }else if (triangleOption == 3){

                       //Type of triangle based on side
                       float sideOne, sideTwo, sideThree;
                       printf("Enter three sides:");
                       scanf("%f%f%f", &sideOne, &sideTwo, &sideThree);

                       if(sideOne + sideTwo > sideThree && sideTwo + sideThree > sideOne && sideThree + sideOne > sideTwo){
                            if(sideOne == sideTwo && sideTwo == sideThree){

                                printf("Equilateral Triangle\n");

                           }else if(sideOne == sideTwo || sideTwo == sideThree || sideThree == sideOne){

                               printf("Isosceles Triangle\n");

                           }else{

                               printf("Scalene Triangle\n");

                           }
                       }else{

                            printf("It is not a triangle\n");

                       }

                    }else{

                        printf("\n");
                        printf("Invalid option, Please choose right one\n");

                    }

                }else if (option == 2){

                    // Circle (Completed by Atika 011211041)
                    printf("\nYou have chosen Circles\n");

                    printf("\nEnter radius:");

                    float radius;
                    scanf("%f", &radius);

                    float pie = 3.14;
                    float area = pie * (radius * radius);
                    float circumference = 2 * pie * radius;

                    printf("\nArea of circle is %.2f\nCircumference of circle is %.2f\n", area,circumference);

                }else if (option == 3){

                    //Quadrilateral (Completed by Tonmoy 011211035)
                    printf("\nYou have chosen Quadrilateral\n");
                    printf("\nWhat do you want to calculate ??\n");
                    printf("1.Rectangle Area & Perimeter \n2.Parallelogram Area & Perimeter\n3.Rhombus Area & Perimeter\n\n");
                    printf("Choose Your Option:");

                    int quadOption;
                    scanf("%d", &quadOption);

                    if(quadOption == 1){

                        // Rectangle
                        printf("You have chosen Rectangle\n");

                        float recLength, recWidth;
                        printf("Enter Length:");
                        scanf("%f", &recLength);
                        printf("Enter Width:");
                        scanf("%f", &recWidth);

                        float recSurArea = recWidth * recLength;
                        float recPerimeter = 2 * (recLength + recWidth);

                        printf("\nRectangle area is %.2f\nRectangle perimeter is %.2f\n", recSurArea, recPerimeter);

                    }else if (quadOption == 2){

                        // Parallelogram
                        printf("You have chosen Parallelogram\n");

                        float parBase, parHeight, parSide;
                        printf("Enter Base:");
                        scanf("%f", &parBase);
                        printf("Enter Height:");
                        scanf("%f", &parHeight);
                        printf("Enter Side:");
                        scanf("%f", &parSide);

                        float parSurArea = parBase * parHeight;
                        float parPerimeter = 2 * (parSide + parBase);

                        printf("\nParallelogram area is %.2f\nParallelogram perimeter is %.2f\n", parSurArea, parPerimeter);

                    }else if (quadOption == 3){

                        // Rhombus
                        printf("You have chosen Rhombus\n");

                        float rbDiaOne, rbDiaTwo, rbSide;
                        printf("Enter Diagonal One:");
                        scanf("%f", &rbDiaOne);
                        printf("Enter Diagonal Two:");
                        scanf("%f", &rbDiaTwo);
                        printf("Enter Side:");
                        scanf("%f", &rbSide);

                        float rbSurArea = (rbDiaOne * rbDiaTwo)/2;
                        float rbPerimeter = 4 * rbSide;

                        printf("\nRhombus area is %.2f\nRhombus perimeter is %.2f\n", rbSurArea, rbPerimeter);

                    }else{

                        printf("\n");
                        printf("Invalid option, Please choose right one\n");

                    }

                }else if (option == 4){

                    //Cube (Completed by Atika 011211041)
                    printf("\nYou have chosen Cube\n");

                    printf("\nEnter edge:");

                    float edge;
                    scanf("%f", &edge);

                    float cubeSurfaceArea = 6 * (edge * edge);
                    float cubeVolume = edge * edge * edge ;

                    printf("\nSurface Area of cube is %.2f\nVolume of cube is %.2f\n", cubeSurfaceArea,cubeVolume);


                }else if (option == 5){

                    //Cylinder(Completed by Ramisa:011202337)

                    printf("\nYou have chosen Cylinder\n");

                    float cylinderRadius, cylinderHeight;
                    float pie = 3.14;
                    printf("Enter radius:");
                    scanf("%f", &cylinderRadius);
                    printf("Enter height:");
                    scanf("%f", &cylinderHeight);

                    float cylinderSurfaceArea = (2 * pie * cylinderRadius * cylinderHeight) + (2 * pie * cylinderRadius * cylinderRadius);
                    float cylinderVolume = pie * (cylinderRadius * cylinderRadius) * cylinderHeight;

                    printf("\nSurface Area of cylinder is %.2f\nVolume of cylinder is %.2f\n", cylinderSurfaceArea, cylinderVolume);

                }else{

                    printf("\n");
                    printf("Invalid option, Please choose right one\n");

                }
            }
    }

    printf("###############   THANK YOU    ################\n");

    return 0;
}
