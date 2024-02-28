#include <stdio.h>
#include "../../lib/objects/objects.h"

int main()
{
    Car* car1 = car_create("VW", "POLO", "GE123456");
    Car* car2 = car_create("VW", "POLO", "GE123457");
    Customer* customer1 = customer_create("John Doe", "Some Street 123");
    Customer* customer2 = customer_create("Jane Doe", "Some Street 321");

    link_car(car1, customer1);
    link_car(car2, customer2);

    Customer** customers = (Customer*[]){customer1, customer2};

    Registry* registry = registry_create(customers, 2);

    print_registry(registry);

    registry_destroy(registry);

}
