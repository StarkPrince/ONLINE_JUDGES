// An online shopping website provides home delivery for products ordered online.
// N delivery persons (with IDs from 0 to N-1) are assigned to deliver parcels in the city.
// When a delivery is scheduled, the branch office informs the delivery person of the distance of the destination from the branch office Customers may update the delivery location even after the delivery is scheduled if the delivery location is updated, the delivery person is informed of the extra distance in a message separate from the mese that informed him of the original distance.
// If the new location is outside the delivery agent of the branch then the delivery person receives extra compensation to deliver the product.
// As per the company rule, extra compensation is given only once to a delivery person.
// The company system generates two types of instructions in the first instruction, the system informs the delivery person of the extra distance for an updated location. The second instruction calculates the total salary of a group of delivery persons having IDs in the given range.

// Write an algorithm to calculate the total salaries of the given group of delivery persons.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DeliveryPerson
{
public:
    int id;
    int salary;
    int extraDistance;
    int totalDistance;
    int totalSalary;
    bool compensation;
    DeliveryPerson(int id, int salary, int extraDistance, int totalDistance, int totalSalary)
    {
        this->id = id;
        this->salary = salary;
        this->extraDistance = extraDistance;
        this->totalDistance = totalDistance;
        this->totalSalary = totalSalary;
        this->compensation = false;
    }

    void updateSalary(int extraDistance)
    {
        if (!compensation && extraDistance > 0)
        {
            this->totalSalary += extraDistance * salary;
            this->compensation = true;
        }
    }

    void updateTotalDistance(int totalDistance)
    {
        this->totalDistance = totalDistance;
    }
};

int rangeSum(vector<DeliveryPerson> &dp, int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += dp[i].totalSalary;
    return sum;
}

int main()
{
    // implement N delivery persons (with IDs from 0 to N-1) are assigned to deliver parcels in the city.
    vector<DeliveryPerson> persons;
    cin >> persons.size();
    for (int i = 0; i < persons.size(); i++)
    {
        int id, salary, extraDistance, totalDistance;
        cin >> id >> salary >> extraDistance >> totalDistance;
        persons.push_back(DeliveryPerson(id, salary, extraDistance, totalDistance, 0));
    }
}