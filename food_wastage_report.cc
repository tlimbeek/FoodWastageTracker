// Theresa Limbeek
// CPSC 121L-14
// 11-23-23
// tlimbeek@csu.fullerton.edu
// tlimbeek

#include "food_wastage_report.h"

#include <algorithm>
#include <map>

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (food_wastage_report.h), only
// if you didn't implement them inline within food_wastage_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the FoodWastageReport
// class.
// ===================================================================
// cycle through food wastage record vector inserting food names to map, for
// each reoccurence of food name, increment element value by 1, and return
// vector of food names with most occurences.
const std::vector<std::string>& FoodWastageReport::MostWastedFoods() const {
  std::vector<std::string> most_wasted_foods{};  // initialize local variable
  std::map<std::string, int> wasted_foods{};
  // create a map of food names, incriment element's value by 1 for each
  // reoccurence.
  for (FoodWastageRecord record : food_wastage_records_) {
    // if record.foodname isn't included in wasted_foods, then insert in
    // wasted_foods with occurence of 1.
    if (wasted_foods.count(record.FoodName()) == 0) {
      wasted_foods.insert({record.FoodName(), 1});
    } else {  // if record.foodname is already included in wasted_foods, then
              // increment value by 1.
      wasted_foods.at(record.FoodName())++;
    }
  }
  // keep track of highest number of occurences
  int num_occur = 0;
  // determines what the highest number of occurences in the wasted_foods map is
  for (std::pair<std::string, int> food : wasted_foods) {
    if (num_occur < food.second) {
      num_occur = food.second;
    }
  }
  // cycles through wasted_foods map looking for occurences equal to the highest
  // number of occurences, then adds the key to vector
  for (std::pair<std::string, int> food : wasted_foods) {
    if (food.second == num_occur) {
      most_wasted_foods.push_back(food.first);  // add food to local variable
    }
  }
  return most_wasted_foods;  // return local variable
}

const std::vector<std::string>& FoodWastageReport::MostCostlyMeals() const {
  std::vector<std::string> most_costly_meals{};
  std::map<std::string, double>
      costly_meals{};  // each element contains name of meal to cost of meal
                       // wasted
  for (FoodWastageRecord record : food_wastage_records_) {
    // if record.meal isn't included in costly_meals, then insert meal in
    // costly_meals with the cost of that meal.
    if (costly_meals.count(record.Meal()) == 0) {
      costly_meals.insert({record.Meal(), record.Cost()});
    } else {  // if record.meal is already included in costly_meals, then add
              // the cost of repeated meal to current cost.
      costly_meals.at(record.Meal()) += record.Cost();
    }
  }
  // keep track of highest cost meal
  double meal_cost = 0.0;
  // determines what the highest cost meal is
  for (std::pair<std::string, double> meal : costly_meals) {
    if (meal_cost < meal.second) {
      meal_cost = meal.second;
    }
  }
  // cycles through costly_meals map looking for cost equal to the highest cost,
  // then adds the key (meal) to most_costly_meals vector
  for (std::pair<std::string, double> meal : costly_meals) {
    if (meal.second == meal_cost) {
      most_costly_meals.push_back(meal.first);  // this line causes an error
    }
  }
  return most_costly_meals;
}

const std::vector<std::string>& FoodWastageReport::CommonWastageReasons()
    const {
  std::vector<std::string> most_common_wastage_reasons{};
  std::map<std::string, int> common_wastage_reasons{};
  // if wastage reason not found in common_wastage_reasons, then insert and set
  // occurence count to 1.
  for (FoodWastageRecord record : food_wastage_records_) {
    if (common_wastage_reasons.count(record.WastageReason()) == 0) {
      common_wastage_reasons.insert({record.WastageReason(), 1});
    } else {  // if wastage reason is found in common_wastage_reasons, then
              // increment occurence count.
      common_wastage_reasons.at(record.WastageReason())++;
    }
  }
  // keep track of highest occurence count.
  int num_occur = 0;
  // find the highest number of occurences in common_wastage_reasons
  for (std::pair<std::string, int> wastage_reason : common_wastage_reasons) {
    if (num_occur < wastage_reason.second) {
      num_occur = wastage_reason.second;
    }
  }
  // cycle through common_wastage_reasons map checking if occurences is equal to
  // highest number of occurences, then adds key to most_common_wastage_reasons
  // vector
  for (std::pair<std::string, int> wastage_reason : common_wastage_reasons) {
    if (wastage_reason.second == num_occur) {
      most_common_wastage_reasons.push_back(wastage_reason.first);
    }
  }
  return most_common_wastage_reasons;
}

const std::vector<std::string>& FoodWastageReport::CommonDisposalMethods()
    const {
  std::vector<std::string> most_common_disposal_methods{};
  std::map<std::string, int> common_disposal_methods{};
  // if disposal mechanism not found in common_disposal_methods, then insert and
  // set occurence count to 1.
  for (FoodWastageRecord record : food_wastage_records_) {
    if (common_disposal_methods.count(record.DisposalMechanism()) == 0) {
      common_disposal_methods.insert({record.DisposalMechanism(), 1});
    } else {  // if disposal mechanism is found in common_disposal_methods, then
              // increment occurence count.
      common_disposal_methods.at(record.DisposalMechanism())++;
    }
  }
  // keep track of highest occurence count.
  int num_occur = 0;
  // find the highest number of occurences in common_disposal_methods
  for (std::pair<std::string, int> disposal_method : common_disposal_methods) {
    if (num_occur < disposal_method.second) {
      num_occur = disposal_method.second;
    }
  }
  // cycle through common_disposal_methods map checking if occurences is equal
  // to highest number of occurences, then adds key to
  // most_common_disposal_methods vector
  for (std::pair<std::string, int> disposal_method : common_disposal_methods) {
    if (disposal_method.second == num_occur) {
      most_common_disposal_methods.push_back(disposal_method.first);
    }
  }
  return most_common_disposal_methods;
}

const std::vector<std::string>& FoodWastageReport::ReductionStrategies() const {
  // possible reduction strategies: "Buy less food", "Cook small servings",
  // "Recycle left overs", "Donate before expiration"
  std::vector<std::string> reduction_strategies{};
  // copy constructs common_wastage_reasons
  std::vector<std::string> common_wastage_reasons{this->CommonWastageReasons()};
  // identify appropriate strategy based off of most common wastage reasons
  // locate expired among most common wastage reasons
  std::vector<std::string>::iterator it = std::find(
      common_wastage_reasons.begin(), common_wastage_reasons.end(), "Expired");
  if (it != common_wastage_reasons
                .end()) {  // if expired is one of the common disposal methods,
                           // then suggest donate before expiration
    reduction_strategies.push_back("Donate before expiration");
  } else {
    reduction_strategies.push_back(
        "Recycle left overs");  // if expired is not one of the common disposal
                                // methods, then suggest recycle leftovers
  }
  // locate tastes bad among most common wastage reasons
  it = std::find(common_wastage_reasons.begin(), common_wastage_reasons.end(),
                 "Tastes bad");
  if (it ==
      common_wastage_reasons
          .end()) {  // if tastes bad is not included in common disposal methods
    if (std::find(common_wastage_reasons.begin(), common_wastage_reasons.end(),
                  "Too much left overs") !=
        common_wastage_reasons
            .end()) {  // if too much left overs is included in common disposal
                       // methods, then suggest small servings and buying less
      reduction_strategies.push_back("Cook small servings");
      reduction_strategies.push_back("Buy less food");
    }
  } else {  // if tastes bad is included in common disposal methods, then
            // suggest buy less food
    reduction_strategies.push_back("Buy less food");
    if (std::find(common_wastage_reasons.begin(), common_wastage_reasons.end(),
                  "Too much left overs") !=
        common_wastage_reasons
            .end()) {  // if too much leftovers is included in common disposal
                       // methods, then suggest cook small servings
      reduction_strategies.push_back("Cook small servings");
    }
  }
  return reduction_strategies;
}
double FoodWastageReport::TotalCost() const {
  double total_cost = 0.0;
  for (FoodWastageRecord record : food_wastage_records_) {
    total_cost += record.Cost();
  }
  return total_cost;
}