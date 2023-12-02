#ifndef FOOD_WASTAGE_RECORD_H_
#define FOOD_WASTAGE_RECORD_H_

#include <iostream>
// Theresa Limbeek
// CPSC 121L-14
// 11-23-23
// tlimbeek@csu.fullerton.edu
// tlimbeek

class FoodWastageRecord {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageRecord class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  const std::string& Date() const { return date_; }
  const std::string& Meal() const { return meal_; }
  const std::string& FoodName() const { return food_name_; }
  const std::string& WastageReason() const { return wastage_reason_; }
  const std::string& DisposalMechanism() const { return disposal_mechanism_; }
  double QuantityOz() const { return quantity_oz_; }
  double Cost() const { return cost_; }

  void SetDate(const std::string& date) { date_ = date; }
  void SetMeal(const std::string& meal) { meal_ = meal; }
  void SetFoodName(const std::string& food_name) { food_name_ = food_name; }
  void SetWastageReason(const std::string& wastage_reason) {
    wastage_reason_ = wastage_reason;
  }
  void SetDisposalMechanism(const std::string& disposal_mechanism) {
    disposal_mechanism_ = disposal_mechanism;
  }
  void SetQuantityOz(double quantity_oz) { quantity_oz_ = quantity_oz; }
  void SetCost(double cost) { cost_ = cost; }

 private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  std::string wastage_reason_;
  std::string disposal_mechanism_;
  double quantity_oz_;
  double cost_;
};

#endif