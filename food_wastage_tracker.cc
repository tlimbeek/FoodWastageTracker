// Theresa Limbeek
// CPSC 121L-14
// 11-23-23
// tlimbeek@csu.fullerton.edu
// tlimbeek

#include "food_wastage_tracker.h"

#include <vector>

bool FoodWastageTracker::AddRecord(const FoodWastageRecord& added_record) {
  for (FoodWastageRecord record : food_wastage_records_) {
    if (record.Date() == added_record.Date() &&
        record.Meal() == added_record.Meal() &&
        record.FoodName() == added_record.FoodName() &&
        record.WastageReason() == added_record.WastageReason() &&
        record.DisposalMechanism() == added_record.DisposalMechanism() &&
        record.QuantityOz() == added_record.QuantityOz() &&
        record.Cost() == added_record.Cost()) {
      return false;
    }
  }
  food_wastage_records_.push_back(added_record);
  return true;
}
bool FoodWastageTracker::DeleteRecord(const FoodWastageRecord& deleted_record) {
  for (int i = 0; i < food_wastage_records_.size(); i++) {
    if (food_wastage_records_.at(i).Date() == deleted_record.Date() &&
        food_wastage_records_.at(i).Meal() == deleted_record.Meal() &&
        food_wastage_records_.at(i).FoodName() == deleted_record.FoodName() &&
        food_wastage_records_.at(i).WastageReason() ==
            deleted_record.WastageReason() &&
        food_wastage_records_.at(i).DisposalMechanism() ==
            deleted_record.DisposalMechanism() &&
        food_wastage_records_.at(i).QuantityOz() ==
            deleted_record.QuantityOz() &&
        food_wastage_records_.at(i).Cost() == deleted_record.Cost()) {
      food_wastage_records_.erase(food_wastage_records_.begin() + i);
      return true;
    }
  }
  return false;
}