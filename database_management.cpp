
#include "database_management.h"

using namespace std;

void createTables() {
        const char* sql = "CREATE TABLE IF NOT EXISTS Vehicles(" \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Type TEXT NOT NULL," \
                      "Brand TEXT NOT NULL," \
                      "Engine REAL NOT NULL," \
                      "FuelType TEXT NOT NULL," \
                      "Mileage INT NOT NULL," \
                      "Year INT NOT NULL," \
                      "Color TEXT NOT NULL," \
                      "Price REAL NOT NULL," \
                      "Model TEXT," \
                      "TopSpeed INT," \
                      "CargoCapacity REAL," \
                      "TowingCapacity REAL," \
                      "MotoType TEXT" \
                      ");";

    const char* sql2 = "CREATE TABLE IF NOT EXISTS SoldVehicles(" \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Type TEXT NOT NULL," \
                      "Brand TEXT NOT NULL," \
                      "Engine REAL NOT NULL," \
                      "FuelType TEXT NOT NULL," \
                      "Mileage INT NOT NULL," \
                      "Year INT NOT NULL," \
                      "Color TEXT NOT NULL," \
                      "Price REAL NOT NULL," \
                      "Model TEXT," \
                      "TopSpeed INT," \
                      "CargoCapacity REAL," \
                      "TowingCapacity REAL," \
                      "MotoType TEXT," \
                      "Date TEXT NOT NULL," \
                      "Name TEXT NOT NULL," \
                      "Surname TEXT NOT NULL," \
                      "Contact TEXT NOT NULL" \
                      ");";
     const char* sql3 = "CREATE TABLE IF NOT EXISTS Customers(" \
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Name TEXT NOT NULL," \
                      "Surname TEXT NOT NULL," \
                      "Contact TEXT NOT NULL" \
                      ");";

    executeSQL(sql);
    executeSQL(sql2);
    executeSQL(sql3);
}

// SQLite database function
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    const int columnWidth1 = 15;
    const int columnWidth2 = 20; 
    const int columnDistance = 2;

    cout << endl;
    for(int i = 0; i < argc; i++) {
        cout << setw(columnWidth1) << left << azColName[i] << setw(columnDistance) << " : " << setw(columnWidth2) << (argv[i] ? argv[i] : "NULL");
        if ((i + 1) % 3 == 0 || i == argc - 1) {
            cout << endl;          
        }
    }
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    return 0;
}

// SQLite database function
void executeSQL(const char* sql) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("dealership.db", &db);
    if(rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(1);
    }

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK) {
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
}


// Implementation of retrieveVehicleDetails function
GetDetails retrieveVehicleDetails(int vehicleID) {
    GetDetails vehicleDetails;

    string sql = "SELECT * FROM Vehicles WHERE ID = " + to_string(vehicleID) + ";";
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("dealership.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Failed to execute SQL query: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(1);
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        if (const unsigned char *typePtr = sqlite3_column_text(stmt, 1))
            vehicleDetails.type = reinterpret_cast<const char*>(typePtr);
        if (const unsigned char *brandPtr = sqlite3_column_text(stmt, 2))
            vehicleDetails.brand = reinterpret_cast<const char*>(brandPtr);
        vehicleDetails.engine = sqlite3_column_double(stmt, 3);
        if (const unsigned char *fuelTypePtr = sqlite3_column_text(stmt, 4))
            vehicleDetails.fuelType = reinterpret_cast<const char*>(fuelTypePtr);
        vehicleDetails.mileage = sqlite3_column_int(stmt, 5);
        vehicleDetails.year = sqlite3_column_int(stmt, 6);
        if (const unsigned char *colorPtr = sqlite3_column_text(stmt, 7))
            vehicleDetails.color = reinterpret_cast<const char*>(colorPtr);
        vehicleDetails.price = sqlite3_column_double(stmt, 8);
        if (const unsigned char *modelPtr = sqlite3_column_text(stmt, 9))
            vehicleDetails.model = reinterpret_cast<const char*>(modelPtr);
        vehicleDetails.topSpeed = sqlite3_column_int(stmt, 10);
        vehicleDetails.cargoCapacity = sqlite3_column_double(stmt, 11);
        vehicleDetails.towingCapacity = sqlite3_column_double(stmt, 12);
        if (const unsigned char *motoTypePtr = sqlite3_column_text(stmt, 13))
            vehicleDetails.motoType = reinterpret_cast<const char*>(motoTypePtr);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return vehicleDetails;
}

// Implementation of retrieveCustomers function
void retrieveCustomers() {
    string sql = "SELECT * FROM Customers;";
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc = sqlite3_open("dealership.db", &db);
    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(1);
    }
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Failed to execute SQL query: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        exit(1);
    }

    // View customers
    cout << "Customers:" << endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *namePtr = sqlite3_column_text(stmt, 1);
        const unsigned char *surnamePtr = sqlite3_column_text(stmt, 2);
        const unsigned char *contactPtr = sqlite3_column_text(stmt, 3);

        string name = reinterpret_cast<const char*>(namePtr);
        string surname = reinterpret_cast<const char*>(surnamePtr);
        string contact = reinterpret_cast<const char*>(contactPtr);

        cout << "ID: " << id << ", Name: " << name << ", Surname: " << surname << ", Contact: " << contact << endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
