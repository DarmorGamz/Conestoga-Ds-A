/********************************************
Author:	Darren Morrison
Email:	dmorrison8832@conestogac.on.ca
SN:		8258832
*********************************************/

/** INCLUDES ******************************************************************/
#include "AssemblyLine.h"
#include <fstream>
#include <iostream>
#include <regex>

/** PUBLIC FUNCTION IMPLEMENTATIONS *******************************************/

/**
*  Main Program entry.
*  @return int Return success.
*/
int main() {
    // Create array of Products. Task will be created based on this list.
	const char* products[] = { "CPU", "GPU", "RAM", "Monitor", "Controller", "VR Headset", "AR Glasses" };
    int ProductArrayLength = (sizeof(products) / sizeof(char*));

    // Add all the Tasks to the AssemblyLine.
    if(ProductArrayLength > 0) { // Skips if there are no Product Tasks to add.
        for(int i = 0; i < ProductArrayLength; i++) {
            Head->Push(new AssemblyLine(new Task((std::string)products[i])));
        }
    }

    // Define product arrays.
    std::vector<Product*> UnProccessedProducts;
    std::vector<Product*> CompletedProducts;
    std::vector<Product*> BackorderedProducts;

    // open a file in read mode.
    std::ifstream file("InputProducts.txt");
    std::string str;

    // Get all products from order(InputProducts)
    int iProductCount = 0;
    

    while(std::getline(file, str)) {
        if(str[0] != '-') { // Serial Number.
            iProductCount++; // Increase Product Count.

            // Create the product.
            Product* tempProduct = new Product();
            tempProduct->SN = stoi(str);
            tempProduct->status = Status::NotReady;

            // Resize array.
            UnProccessedProducts.push_back(tempProduct);
        } else {
            // Create Item
            Item* tempItem = new Item();

            // Remove dash
            tempItem->Name = str.erase(0, 1);

            // Find next empty index for component.
            int index = 0;
            for(int i = 0; i < 8; i++) {
                if(UnProccessedProducts[iProductCount - 1]->Components[i].Name == "") {
                    index = i;
                    break;
                }
            }
            
            // Add component to Product.
            UnProccessedProducts[iProductCount - 1]->Components[index] = *tempItem;
        }
    }
    
    // Main statemachine. Loop through until all products have gone through
    while(CompletedProducts.size() + BackorderedProducts.size() != iProductCount) {
        // Read task from file and add to First Assembly Line task.
        if (!UnProccessedProducts.empty()) { // There are products to add
            Head->AddProduct(UnProccessedProducts[0]);
            UnProccessedProducts.erase(UnProccessedProducts.begin());
        }

        // Run Assembly Line Back to Front.
        AssemblyLine* LastReverseOrder = nullptr;
        while(LastReverseOrder != Head) {
            AssemblyLine* prev = nullptr;
            AssemblyLine* curr = Head;
            while(curr != LastReverseOrder) {
                prev = curr;
                curr = curr->GetpNext();
            }
            LastReverseOrder = prev;
            prev->Run();

        }
        AssemblyLine* curr = Head;
        while(curr != nullptr) {
            Product *tempProduct = curr->MoveProduct();
            if(tempProduct != nullptr && curr->GetpNext() != nullptr) {
                if(tempProduct->status != BackOrdered) {
                    tempProduct->status = Status::NotReady;
                }
                curr->GetpNext()->AddProduct(tempProduct);
            } else if(tempProduct != nullptr && curr->GetpNext() == nullptr) {
                if(tempProduct->status == Status::Ready) {
                    CompletedProducts.push_back(tempProduct);
                } else if (tempProduct->status == Status::BackOrdered) {
                    BackorderedProducts.push_back(tempProduct);
                } else {
                    // Error
                }
            }
            curr = curr->GetpNext();
        }
    }

    // Output Each lists quanitity count.
    std::cout << "CompletedSize: " << CompletedProducts.size() << std::endl;
    std::cout << "BackorderedSize: " << BackorderedProducts.size() << std::endl << std::endl;

    // Output formatted Completed List.
    std::cout << "Completed List: " << std::endl;
    for(int i = 0; i < CompletedProducts.size(); i++) {
        std::cout << "   Serial Number: " << CompletedProducts[i]->SN << std::endl;
        std::cout << "   Status: " << CompletedProducts[i]->status << std::endl;
        for(int k = 0; k < 8; k++) {
            if(CompletedProducts[i]->Components[k].Name != "") {
                std::cout << "      Component: " << CompletedProducts[i]->Components[k].Name << std::endl;
                std::cout << "      Serial: " << CompletedProducts[i]->Components[k].SN << std::endl;
            }
        }
    }

    // Output formatted Backordered List.
    std::cout << "Backordered List: " << std::endl;
    for(int i = 0; i < BackorderedProducts.size(); i++) {
        std::cout << "   Serial Number: " << BackorderedProducts[i]->SN << std::endl;
        std::cout << "   Status: " << BackorderedProducts[i]->status << std::endl;
        for(int k = 0; k < 8; k++) {
            if(BackorderedProducts[i]->Components[k].Name != "") {
                std::cout << "      Component: " << BackorderedProducts[i]->Components[k].Name << std::endl;
                std::cout << "      Serial: " << BackorderedProducts[i]->Components[k].SN << std::endl;
            }
        }
    }

    // Return Success.
    return 1;
}