#include "food_wastage_tracker_backend.h"

#include <filesystem>

#include "food_wastage_record.h"
#include "food_wastage_report.h"
#include "server_utils/rapidjson/document.h"      // rapidjson's DOM-style API
#include "server_utils/rapidjson/prettywriter.h"  // for stringify JSON
#include "server_utils/rapidjson/rapidjson.h"
#include "server_utils/rapidjson/stringbuffer.h"  // wrapper of C stream for prettywriter as output
#include "server_utils/rapidjson/writer.h"

// Util function to convert a FoodWastageRecord class object into a serialized
// JSON object.
void SerializeFoodWastageRecordToJSON(
    const FoodWastageRecord &record,
    rapidjson::Writer<rapidjson::StringBuffer> *writer) {
  writer->StartObject();

  writer->String("date_");  // DO NOT MODIFY
  std::string date;
  // 1. Use the accessor/getter function for date from the
  // FoodWastageRecord class object to get the date and store it in the date
  // string declared above.
  date = record.Date();
  writer->String(date.c_str());

  writer->String("meal_");  // DO NOT MODIFY
  std::string meal;
  // 2. Use the accessor/getter function for meal from the
  // FoodWastageRecord class object to get the meal and store it in the meal
  // string declared above.
  meal = record.Meal();

  writer->String(meal.c_str());

  writer->String("food_name_");  // DO NOT MODIFY
  std::string food_name;
  // 3. Use the accessor/getter function for food name from the
  // FoodWastageRecord class object to get the food name and store it in the
  // food_name string declared above.
  food_name = record.FoodName();

  writer->String(food_name.c_str());

  writer->String("qty_in_oz_");  // DO NOT MODIFY
  double quantity;
  // 4. Use the accessor/getter function for quantity from the
  // FoodWastageRecord class object to get the quantity and store it in the
  // quantity variable declared above.
  quantity = record.QuantityOz();

  writer->Double(quantity);

  writer->String("wastage_reason_");  // DO NOT MODIFY
  std::string wastage_reason;
  // 5. Use the accessor/getter function for wastage reason from the
  // FoodWastageRecord class object to get the wastage reason and store it in
  // the wastage_reason string declared above.
  wastage_reason = record.WastageReason();

  writer->String(wastage_reason.c_str());

  writer->String("disposal_mechanism_");  // DO NOT MODIFY
  std::string disposal_mechanism;
  // 6. Use the accessor/getter function for disposal mechanism from the
  // FoodWastageRecord class object to get the disposal mechanism and store it
  // in the disposal_mechanism string declared above.
  disposal_mechanism = record.DisposalMechanism();

  writer->String(disposal_mechanism.c_str());

  writer->String("cost_");  // DO NOT MODIFY
  double cost;
  // 7. Use the accessor/getter function for cost from the
  // FoodWastageRecord class object to get the cost and store it in the cost
  // variable declared above.
  cost = record.Cost();

  writer->Double(cost);

  writer->EndObject();
}

// Util function to convert a serialized JSON object in to a FoodWastageRecord
// class object.
FoodWastageRecord DeserializeFoodWastageRecordFromJSON(
    const rapidjson::Value &json_obj) {
  FoodWastageRecord record;

  /*  1. Use the mutator/setter function for date from the FoodWastageRecord
   *  class to set the date in `record` object. You can get the date from JSON
   *  object as follows: `json_obj["date_"].GetString()`.
   *  Use that as an function  argument for the mutator that you'll call.
   */
   record.SetDate(json_obj["date_"].GetString());

  /*  2. Use the mutator/setter function for meal from the FoodWastageRecord
   *  class to set the meal in `record` object. You can get the meal from JSON
   *  object as follows: `json_obj["meal_"].GetString()`.
   *  Use that as an function  argument for the mutator that you'll call.
   */
   record.SetMeal(json_obj["meal_"].GetString());

  /* 3. Use the mutator/setter function for food name from the
   * FoodWastageRecord class to set the food name in `record` object. You can
   * get the food name from JSON object as follows:
   * `json_obj["food_name_"].GetString()`. Use that as an function  argument for
   * the mutator that you'll call.
   */
   record.SetFoodName(json_obj["food_name_"].GetString());

  /* 4. Use the mutator/setter function for quantity from the
   * FoodWastageRecord class to set the quantity in `record` object. You can get
   * the quantity from JSON object as follows:
   * `json_obj["qty_in_oz_"].GetDouble()`. Use that as an function  argument for
   * the mutator that you'll call.
   */
   record.SetQuantityOz(json_obj["qty_in_oz_"].GetDouble());

  /* 5. Use the mutator/setter function for wastage reason from the
   * FoodWastageRecord class to set the wastage reason in `record` object. You
   * can get the wastage reason from JSON object as follows:
   * `json_obj["wastage_reason_"].GetString()`. Use that as an function argument
   * for the mutator that you'll call.
   */
   record.SetWastageReason(json_obj["wastage_reason_"].GetString());

  /* 6. Use the mutator/setter function for disposal mechanism from the
   * FoodWastageRecord class to set the disposal mechanism in `record` object.
   * You can get the disposal mechanism from JSON object as follows:
   * `json_obj["disposal_mechanism_"].GetString()`. Use that as an function
   * argument for the mutator that you'll call.
   */
   record.SetDisposalMechanism(json_obj["disposal_mechanism_"].GetString());

  /*  7. Use the mutator/setter function for cost from the FoodWastageRecord
   *  class to set the cost in `record` object. You can get the cost from JSON
   *  object as follows: `json_obj["cost_"].GetDouble()`.
   *  Use that as an function  argument for the mutator that you'll call.
   */
   record.SetCost(json_obj["cost_"].GetDouble());
  return record;
}

// Util function to convert a FoodWastageRecord class object into a Crow JSON
// object.
crow::json::wvalue FoodWastageRecordToCrowJSON(
    const FoodWastageRecord &record) {
  crow::json::wvalue record_json({});

  std::string date;
  // 1. Use the accessor/getter function for date from the
  // FoodWastageRecord class object to get the date and store it in the date
  // string declared above.
  date = record.Date();
  record_json["date"] = date;

  std::string meal;
  // 2. Use the accessor/getter function for meal from the
  // FoodWastageRecord class object to get the meal and store it in the meal
  // string declared above.
  meal = record.Meal();
  record_json["meal"] = meal;

  std::string food_name;
  // 3. Use the accessor/getter function for food name from the
  // FoodWastageRecord class object to get the food name and store it in the
  // food_name string declared above.
  food_name = record.FoodName();
  record_json["food_name"] = food_name;

  double quantity;
  // 4. Use the accessor/getter function for quantity from the
  // FoodWastageRecord class object to get the quantity and store it in the
  // quantity variable declared above.
  quantity = record.QuantityOz();
  record_json["qty_in_oz"] = quantity;

  std::string wastage_reason;
  // 5. Use the accessor/getter function for wastage reason from the
  // FoodWastageRecord class object to get the wastage reason and store it in
  // the wastage_reason string declared above.
  wastage_reason = record.WastageReason();
  record_json["wastage_reason"] = wastage_reason;

  std::string disposal_mechanism;
  // 6. Use the accessor/getter function for disposal mechanism from the
  // FoodWastageRecord class object to get the disposal mechanism and store it
  // in the disposal_mechanism string declared above.
  disposal_mechanism = record.DisposalMechanism();
  record_json["disposal_mechanism"] = disposal_mechanism;

  double cost;
  // 7. Use the accessor/getter function for cost from the
  // FoodWastageRecord class object to get the cost and store it in the cost
  // variable declared above.
  cost = record.Cost();
  record_json["cost"] = cost;
  return record_json;
}

// Util function to convert a FoodWastageReport class object into a serialized
// JSON object.
crow::json::wvalue FoodWastageReportToCrowJSON(
    const FoodWastageReport &report) {
  crow::json::wvalue report_json({});

  std::vector<std::string> most_common_disposal_mechanisms{};
  // TODO 1: Call the member function of FoodWastageReport class that returns
  // all the most common disposal mechanisms as a vector of strings. Store the
  // result in the vector declared above.
  most_common_disposal_mechanisms = report.CommonDisposalMethods();
  report_json["most_common_disposal_mechanism_"] =
      most_common_disposal_mechanisms;

  std::vector<std::string> most_commonly_wasted_foods{};
  // TODO 2: Call the member function of FoodWastageReport class that returns
  // all the most commonly wasted foods as a vector of strings. Store the result
  // in the vector declared above.
  most_commonly_wasted_foods = report.MostWastedFoods();
  report_json["most_commonly_wasted_food_"] = most_commonly_wasted_foods;

  std::vector<std::string> most_common_wastage_reasons{};
  // TODO 3: Call the member function of FoodWastageReport class that returns
  // all the most commonwastage reasons as a vector of strings. Store the result
  // in the vector declared above.
  most_common_wastage_reasons = report.CommonWastageReasons();
  report_json["most_common_wastage_reason_"] = most_common_wastage_reasons;

  std::vector<std::string> most_costly_waste_producing_meals{};
  // TODO 4: Call the member function of FoodWastageReport class that returns
  // all the most costly waste producing meals as a vector of strings. Store the
  // result in the vector declared above.
  most_costly_waste_producing_meals = report.MostCostlyMeals();
  report_json["most_waste_producing_meal_"] = most_costly_waste_producing_meals;

  std::vector<std::string> suggested_strategies_to_reduce_waste{};
  // TODO 5: Call the member function of FoodWastageReport class that returns
  // all the suggested strategies as a vector of strings. Store the result in
  // the vector declared above.
  suggested_strategies_to_reduce_waste = report.ReductionStrategies();
  report_json["suggested_strategies_to_reduce_waste_"] =
      suggested_strategies_to_reduce_waste;

  double total_cost_of_wastage = -9999.0;
  // TODO 6: Call the member function of FoodWastageReport class that returns
  // the total cost of wastage as a double. Store the result in the double
  // declared.
  total_cost_of_wastage = report.TotalCost();
  report_json["total_cost_of_food_wasted_"] = total_cost_of_wastage;
  return report_json;
}

// Util function to convert a crow query string into a FoodWastageRecord class
// object.
FoodWastageRecord QueryStringToFoodWastageRecord(
    const crow::query_string &query_string) {
  FoodWastageRecord record;

  // TODO 1. Get the date from the query_string using query_string.get("date"),
  // and set it in the `record` object using the setter in FoodWastageRecord
  // class.
  record.SetDate(query_string.get("date"));

  // TODO 2. Get the meal from the query_string using query_string.get("meal"),
  // and set it in the `record` object using the setter in FoodWastageRecord
  // class.
  record.SetMeal(query_string.get("meal"));

  // TODO 3. Get the food name from the query_string using
  // query_string.get("food_name"), and set it in the `record` object using the
  // setter in FoodWastageRecord class.
  record.SetFoodName(query_string.get("food_name"));

  // TODO 4. Get the quantity from the query_string using
  // std::stod(query_string.get("qty_in_oz")), and set it in the `record` object
  // using the setter in FoodWastageRecord class.
  record.SetQuantityOz(std::stod(query_string.get("qty_in_oz")));

  // TODO 5. Get the wastage reason from the query_string using
  // query_string.get("wastage_reason"), and set it in the `record` object using
  // the setter in FoodWastageRecord class.
  record.SetWastageReason(query_string.get("wastage_reason"));

  // TODO 6. Get the disposal mechanism from the query_string using
  // query_string.get("disposal_mechanism"), and set it in the `record` object
  // using the setter in FoodWastageRecord class.
  record.SetDisposalMechanism(query_string.get("disposal_mechanism"));

  // TODO 7. Get the cost from the query_string using
  // std::stod(query_string.get("cost")), and set it in the `record` object
  // using the setter in FoodWastageRecord class.
  record.SetCost(std::stod(query_string.get("cost")));

  return record;
}

bool FoodWastageTrackerBackend::LoadRecordsFromJSONFile() {
  std::ifstream records_file{food_wastage_records_filepath_};
  if (!records_file.is_open()) {
    std::filesystem::remove(food_wastage_records_filepath_);
    return false;
  }

  std::stringstream buffer;
  buffer << records_file.rdbuf();

  std::string s = buffer.str();
  rapidjson::Document doc;

  if (s.empty()) {
    std::filesystem::remove(food_wastage_records_filepath_);
    return false;
  }

  std::string validJson(s);

  bool doc_parse_error = doc.Parse(validJson.c_str()).HasParseError();
  if (doc_parse_error || !doc.IsArray()) {
    std::filesystem::remove(food_wastage_records_filepath_);
    return false;
  }

  for (rapidjson::Value::ConstValueIterator itr = doc.Begin(); itr != doc.End();
       ++itr) {
    FoodWastageRecord record = DeserializeFoodWastageRecordFromJSON(*itr);
    // Call the member function in the FoodWastageTracker class, on the
    // member object that you added in food_wastage_tracker.h, that
    // adds a `record`.
    food_wastage_tracker_.AddRecord(record);
  }

  records_file.close();
  return true;
}

bool FoodWastageTrackerBackend::WriteRecordsToJSONFile() const {
  std::ofstream records_file{food_wastage_records_filepath_};
  rapidjson::StringBuffer ss;
  rapidjson::Writer<rapidjson::StringBuffer> writer(ss);
  writer.StartArray();
  const std::vector<FoodWastageRecord>& records = food_wastage_tracker_.GetFoodWastageRecords();
  // Call the member function in the FoodWastageTracker class, on the
  // member object that you added in food_wastage_tracker.h, that returns all
  // the FoodWastageRecord objects. Store the returned records in the vector
  // declared above. Also change the data type of the records vector to `const
  // std::vector<FoodWastageRecord>&`.
  for (FoodWastageRecord record : records) {
    SerializeFoodWastageRecordToJSON(record, &writer);
  }
  writer.EndArray();

  records_file << ss.GetString();

  records_file.flush();
  records_file.close();
  return true;
}

crow::json::wvalue FoodWastageTrackerBackend::AddRecord(
    const crow::query_string &query_string) {
  FoodWastageRecord record = QueryStringToFoodWastageRecord(query_string);
  crow::json::wvalue status;
  bool add_result = false;
  // Call the member function in the FoodWastageTracker class, on the
  // member object that you added in food_wastage_tracker.h, that adds a
  // `record` and returns the status of the add operation as a bool. Store the
  // returned value in the bool declared above.
  add_result = food_wastage_tracker_.AddRecord(record);
  status["success"] = add_result;
  return status;
}

crow::json::wvalue FoodWastageTrackerBackend::DeleteRecord(
    const crow::query_string &query_string) {
  FoodWastageRecord record = QueryStringToFoodWastageRecord(query_string);
  crow::json::wvalue status;
  bool delete_result = false;
  // TODO: Call the member function in the FoodWastageTracker class, on the
  // member object that you added in food_wastage_tracker.h, that deletes
  // `record` and returns the status of the delete operation as a bool. Store
  // the returned value in the bool declared above.
  
  //////////////////////////////////////////////////////////////////////////////this line specifically causes an error:
  //delete_result = food_wastage_tracker_.DeleteRecord(record);
  status["success"] = delete_result;
  return status;
}

crow::json::wvalue FoodWastageTrackerBackend::GetRecords() const {
  // Call the member function in the FoodWastageTracker class, on the
  // member object that you added in food_wastage_tracker.h, that returns all
  // the FoodWastageRecord objects. Store the returned records in the vector
  // declared above. Also change the data type of the records vector to `const
  // std::vector<FoodWastageRecord>&`.
  const std::vector<FoodWastageRecord> &records =
      food_wastage_tracker_.GetFoodWastageRecords();
  crow::json::wvalue records_json({});
  records_json["num_records"] = records.size();

  std::vector<crow::json::wvalue> record_json_vector;
  for (const FoodWastageRecord &record : records) {
    record_json_vector.push_back(FoodWastageRecordToCrowJSON(record));
  }
  records_json["record_array"] = std::move(record_json_vector);
  return records_json;
}
crow::json::wvalue FoodWastageTrackerBackend::GetFoodWastageReport() const {
  FoodWastageReport generated_report = food_wastage_tracker_.GetFoodWastageReport();
  // TODO: Call the member function in the FoodWastageTracker class, on the
  // member object that you added in food_wastage_tracker.h, that generates a
  // FoodWastageReport object using all the FoodWastageRecords and returns it.
  // Store the returned value in the `generated_report` object declared above.
  return FoodWastageReportToCrowJSON(generated_report);
}