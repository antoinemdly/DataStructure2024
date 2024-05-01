#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// TODO: Implement
Car *car_create(char *brand, char *model, char *license){
    Car *car = malloc(sizeof(Car));
    car->brand = brand;
    car->model = model;
    car->license = license;
    return car;
}

Customer *customer_create(char *name, char *address){
    Customer *customer = malloc(sizeof(Customer));
    customer->name = name;
    customer->address = address;
    return customer;
}

Registry *registry_create(Customer **customers, int size){
    Registry *registry = malloc(sizeof(Registry));
    registry->customers = customers;
    registry->size = size;
    return registry;
}

void car_destroy(Car *car){
    free(car->brand);
    free(car->license);
    free(car->model);

    free(car);
}
void customer_destroy(Customer *customer){
    free(customer->name);
    free(customer->address);
    customer->car = NULL;
    free(customer);
}
void registry_destroy(Registry *registry){
    free(registry);
}

void link_car(Car *car, Customer *customer){
    customer->car = car;
    // car->customer = customer;
}

void print_registry(Registry *registry){
    for (int i = 0; i < registry->size; i++){

        printf("Name : %s\n", registry->customers[i]->name);
        printf("Adress : %s\n", registry->customers[i]->address);

        printf("    brand : %s\n",registry->customers[i]->car->brand);
        printf("    model : %s\n",registry->customers[i]->car->model);
        printf("    license : %s\n",registry->customers[i]->car->license);
    }
}