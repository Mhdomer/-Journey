
#include <iostream>
#include <string>
#include <map>
#include <cmath>

struct CarInfo {
    int model;
    int variant;
    int region;
    std::string paint_type;
    double price; 
    double down_payment;
    double interest_rate;
    int repayment_period;
};

CarInfo get_data() {
    CarInfo data;

    std::cout << "Car Info" << std::endl;

    std::cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
    std::cin >> data.model;

    std::cout << "Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
    std::cin >> data.variant;

    std::cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
    std::cin >> data.region;

    std::cout << "Paint Type: ";
    std::cin >> data.paint_type;

    std::cout << "Price (MYR): ";
    std::cin >> data.price;

    std::cout << "Down Payment (MYR): ";
    std::cin >> data.down_payment;

    std::cout << "Interest Rate (%): ";
    std::cin >> data.interest_rate;

    std::cout << "Repayment period (in years): ";
    std::cin >> data.repayment_period;

    return data;
}

double calculate_loan(const CarInfo& data) {
    double total_loan_amount = data.price - data.down_payment;
    double interest_rate = data.interest_rate / 100;
    double monthly_interest_rate = interest_rate / 12;
    int repayment_period_in_months = data.repayment_period * 12;
 
    double power = 1 + monthly_interest_rate;
    for (int i = 0; i < repayment_period_in_months; ++i) {
        power *= (1 + monthly_interest_rate);
    }

    double monthly_installment = (total_loan_amount * monthly_interest_rate * power) / (power - 1);

    return monthly_installment;
}


void display_data(const CarInfo& data) {
    std::cout << "\nCar Info" << std::endl;
    std::cout << "Model: ";
    switch (data.model) {
        case 1:
            std::cout << "X50" << std::endl;
            break;
        case 2:
            std::cout << "Exora" << std::endl;
            break;
        case 3:
            std::cout << "Persona" << std::endl;
            break;
    }
    std::cout << "Variant: ";
    switch (data.variant) {
        case 1:
            std::cout << "1.6L Standard CVT" << std::endl;
            break;
        case 2:
            std::cout << "1.6L Premium CVT" << std::endl;
            break;
    }
    std::cout << "Region: ";
    switch (data.region) {
        case 1:
            std::cout << "Peninsular Malaysia" << std::endl;
            break;
        case 2:
            std::cout << "East Malaysia" << std::endl;
            break;
    }
    std::cout << "Paint Type: " << data.paint_type << std::endl;
    std::cout << "Price (MYR): " << data.price << std::endl;
    std::cout << "Down Payment (MYR): " << data.down_payment << std::endl;
    std::cout << "Interest Rate (%): " << data.interest_rate << std::endl;
    std::cout << "Repayment period (in years): " << data.repayment_period << std::endl;
    std::cout << "MONTHLY INSTALLMENT (MYR): " << calculate_loan(data) << std::endl;
}

int main() {
    while (true) {
        CarInfo data = get_data();
        display_data(data);

        char choice;
        std::cout << "\nContinue? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') {
            break;
        } 
    }

    return 0;
}
