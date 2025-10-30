// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.30;

contract DigitalAssetRegistry {
    
    struct Asset {
        string name;       // Name of the asset
        string hash;       // Cryptographic hash of the asset
        address owner;     // Current owner
        uint256 timestamp; // Registration timestamp
    }
    
    uint256 public assetCount;                 // Total number of assets
    mapping(uint256 => Asset) private assets; // Asset storage
    
    // Events
    event AssetRegistered(uint256 indexed assetId, address indexed owner, string hash);
    event OwnershipTransferred(uint256 indexed assetId, address indexed from, address indexed to);
    
    // Constructor (empty for safety)
    constructor() {
        assetCount = 0;
    }
    
    // Register a new digital asset
    function registerAsset(string memory _name, string memory _hash) external {
        require(bytes(_name).length > 0, "Asset name required");
        require(bytes(_hash).length > 0, "Asset hash required");

        assetCount++;
        assets[assetCount] = Asset({
            name: _name,
            hash: _hash,
            owner: msg.sender,
            timestamp: block.timestamp
        });
        
        emit AssetRegistered(assetCount, msg.sender, _hash);
    }
    
    // Transfer ownership of an asset
    function transferOwnership(uint256 _assetId, address _newOwner) external {
        require(_assetId > 0 && _assetId <= assetCount, "Invalid asset ID");
        require(msg.sender == assets[_assetId].owner, "Not the owner");
        require(_newOwner != address(0), "Invalid new owner");

        address oldOwner = assets[_assetId].owner;
        assets[_assetId].owner = _newOwner;
        
        emit OwnershipTransferred(_assetId, oldOwner, _newOwner);
    }
    
    // Verify an asset's integrity
    function verifyAsset(uint256 _assetId, string memory _hash) external view returns (bool) {
        require(_assetId > 0 && _assetId <= assetCount, "Invalid asset ID");
        return keccak256(bytes(assets[_assetId].hash)) == keccak256(bytes(_hash));
    }
    
    // Optional: View asset details
    function getAsset(uint256 _assetId) external view returns (string memory, string memory, address, uint256) {
        require(_assetId > 0 && _assetId <= assetCount, "Invalid asset ID");
        Asset memory a = assets[_assetId];
        return (a.name, a.hash, a.owner, a.timestamp);
    }
}