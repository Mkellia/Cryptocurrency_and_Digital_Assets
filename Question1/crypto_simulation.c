#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ASSETS 100

// Structure for cryptocurrency purchase
typedef struct {
    char cryptoName[20];
    double amountUSD;
    double pricePerCoin;
    double coinsPurchased;
    char transactionID[20];
} Transaction;

// Structure for digital asset
typedef struct {
    int id;
    char owner[50];
    char assetName[50];
    char hash[64];
} DigitalAsset;

DigitalAsset blockchain[MAX_ASSETS];
int assetCount = 0;

// Function to generate a random transaction ID
void generateTransactionID(char *id) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 10; i++)
        id[i] = charset[rand() % (sizeof(charset) - 1)];
    id[10] = '\0';
}

// Function to simulate cryptocurrency purchase
void simulatePurchase() {
    Transaction tx;
    int choice;
    
    printf("\n=== Cryptocurrency Purchase Simulation ===\n");
    printf("Select Cryptocurrency:\n");
    printf("1. Bitcoin (BTC)\n");
    printf("2. Ethereum (ETH)\n");
    printf("3. Cardano (ADA)\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: strcpy(tx.cryptoName, "Bitcoin"); tx.pricePerCoin = 65000.0; break;
        case 2: strcpy(tx.cryptoName, "Ethereum"); tx.pricePerCoin = 3500.0; break;
        case 3: strcpy(tx.cryptoName, "Cardano"); tx.pricePerCoin = 0.5; break;
        default: printf("Invalid choice.\n"); return;
    }

    printf("Enter amount in USD to spend: ");
    scanf("%lf", &tx.amountUSD);

    tx.coinsPurchased = tx.amountUSD / tx.pricePerCoin;
    generateTransactionID(tx.transactionID);

    printf("\n--- Transaction Summary ---\n");
    printf("Cryptocurrency: %s\n", tx.cryptoName);
    printf("Amount Spent: $%.2f\n", tx.amountUSD);
    printf("Price per Coin: $%.2f\n", tx.pricePerCoin);
    printf("Coins Purchased: %.6f\n", tx.coinsPurchased);
    printf("Transaction ID: %s\n", tx.transactionID);
}

// Function to simulate hashing (simple mock hash)
void generateHash(char *input, char *output) {
    unsigned long hash = 5381;
    int c;
    while ((c = *input++))
        hash = ((hash << 5) + hash) + c;
    sprintf(output, "%lx", hash);
}

// Register new digital asset
void registerAsset() {
    if (assetCount >= MAX_ASSETS) {
        printf("Blockchain storage full!\n");
        return;
    }

    DigitalAsset asset;
    printf("\n=== Register Digital Asset ===\n");
    printf("Enter asset name: ");
    scanf(" %[^\n]s", asset.assetName);
    printf("Enter owner name: ");
    scanf(" %[^\n]s", asset.owner);

    asset.id = assetCount + 1;

    char data[200];
    sprintf(data, "%d%s%s", asset.id, asset.assetName, asset.owner);
    generateHash(data, asset.hash);

    blockchain[assetCount++] = asset;

    printf("\nAsset Registered Successfully!\n");
    printf("Asset ID: %d\n", asset.id);
    printf("Owner: %s\n", asset.owner);
    printf("Asset Name: %s\n", asset.assetName);
    printf("Asset Hash: %s\n", asset.hash);
}

// Verify asset ownership and authenticity
void verifyAsset() {
    int id;
    char owner[50];

    printf("\n=== Verify Digital Asset ===\n");
    printf("Enter Asset ID: ");
    scanf("%d", &id);
    printf("Enter Owner Name: ");
    scanf(" %[^\n]s", owner);

    for (int i = 0; i < assetCount; i++) {
        if (blockchain[i].id == id && strcmp(blockchain[i].owner, owner) == 0) {
            printf("\nAsset Found!\n");
            printf("Asset ID: %d\n", blockchain[i].id);
            printf("Asset Name: %s\n", blockchain[i].assetName);
            printf("Owner: %s\n", blockchain[i].owner);
            printf("Hash: %s\n", blockchain[i].hash);
            printf("✅ Ownership and authenticity verified.\n");
            return;
        }
    }
    printf("❌ Asset not found or owner mismatch.\n");
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("\n=== Cryptocurrency & Blockchain Simulation Menu ===\n");
        printf("1. Simulate Cryptocurrency Purchase\n");
        printf("2. Register Digital Asset\n");
        printf("3. Verify Digital Asset\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: simulatePurchase(); break;
            case 2: registerAsset(); break;
            case 3: verifyAsset(); break;
            case 4: printf("Exiting simulation. Goodbye!\n"); break;
            default: printf("Invalid option.\n");
        }
    } while(choice != 4);

    return 0;
}
