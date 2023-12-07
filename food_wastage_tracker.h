#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

#include "food_wastage_record.h"
#include "food_wastage_report.h"

// Theresa Limbeek
// CPSC 121L-14
// 11-23-23
// tlimbeek@csu.fullerton.edu
// tlimbeek

class FoodWastageTracker {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageTracker class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  bool AddRecord(const FoodWastageRecord& added_record);
  // extra credit:
  bool DeleteRecord(const FoodWastageRecord& deleted_record);
  const std::vector<FoodWastageRecord>& GetFoodWastageRecords() const {
    return food_wastage_records_;
  }
  const FoodWastageReport& GetFoodWastageReport() const {
    // Generates and returns a food wastage report
    FoodWastageReport food_wastage_report{food_wastage_records_};
    return food_wastage_report;
  }

 private:
  std::vector<FoodWastageRecord> food_wastage_records_;
};

#endif