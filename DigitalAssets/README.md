# **Blockchain-Based Digital Asset Security System**

## **Project Overview**

This project demonstrates how blockchain can be used to securely register, verify, and transfer digital assets. The system uses **Ethereum smart contracts**, deployed on the **Sepolia test network** via **Remix IDE**, with **MetaMask** handling wallet interactions. The frontend, built with **React and Ethers.js**, provides a user-friendly interface for interacting with the blockchain.

---

## **Features**

* **Register Digital Assets:** Securely register asset metadata and hash on Ethereum blockchain
* **Transfer Ownership:** Transfer ownership safely with verification
* **Verify Asset Integrity:** Confirm asset authenticity using cryptographic hashes
* **Event Logging:** Track all transactions transparently
* **User-Friendly Interface:** React-based web application with MetaMask integration

---

## **Getting Started**

### **Prerequisites**

* Node.js (v16 or higher) and npm installed
* MetaMask wallet installed in your browser
* Sepolia ETH for testing (obtain from Sepolia faucet)
* Remix IDE for smart contract compilation and deployment

---

### **Installation**

1. Clone the repository:

```bash
git clone [YOUR_REPOSITORY_LINK]
```

2. Navigate to the project folder:

```bash
cd [PROJECT_FOLDER]
```

3. Install dependencies:

```bash
npm install
```

4. Start the frontend:

```bash
npm start
```

The web application will open at `http://localhost:3000`.

---

## **Usage**

### **1. Connect Wallet**

* Open the frontend and connect your **MetaMask wallet**
* Make sure MetaMask is set to the **Sepolia network**

### **2. Register a Digital Asset**

* Enter the asset hash, metadata, and description
* Click **Register** to store the asset on the blockchain

### **3. Transfer Ownership**

* Select an asset you own
* Enter the recipient’s Ethereum address
* Click **Transfer** to securely change ownership

### **4. Verify Asset**

* Select the asset you want to verify
* The system will confirm ownership and display asset metadata

---

## **Smart Contract Deployment**

* Developed in **Solidity (v0.8.x)**
* Deployed using **Remix IDE** on **Sepolia test network**
* Contract manages:

  * Asset registration
  * Ownership transfer
  * Integrity verification

**Contract Address (Sepolia):** [YOUR_CONTRACT_ADDRESS]

---

## **Project Structure**

```
/frontend         # React frontend code
/src
  /components     # UI components
  /utils          # Helper functions
  App.tsx         # Main application
/DigitalAsset.sol  # Smart contract
README.md          # Project documentation
```

---

## **Testing**

* All smart contract functions were tested using Remix and Sepolia ETH
* Verified asset registration, ownership transfer, and integrity
* Transactions confirmed on **Sepolia testnet explorer**

---

## **Future Improvements**

* Integrate **IPFS** for storing actual asset files
* Develop a **mobile application**
* Enable **batch registration** for multiple assets
* Implement **multi-signature wallets**
* Deploy on **Ethereum mainnet**

---
