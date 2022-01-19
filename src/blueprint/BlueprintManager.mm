//
//  BlueprintManager.mm
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#include "BlueprintManager.hpp"

BlueprintManager::BlueprintManager(const grumble::FileManager& fileManager) :
_fileManager(fileManager) {
    parseBlueprint("example_blueprint");
}

void BlueprintManager::parseBlueprint(std::string filename) {
    nlohmann::json root = _fileManager.loadJson(filename);
    
    // Determine the size of the blueprint
    BlueprintDataModel blueprint;
    
    blueprint.width = root.value("width", 0);
    blueprint.height = root.value("height", 0);
    
    // Parse the individual cells
    nlohmann::json layers = root.value("layers", nlohmann::json());
    for (nlohmann::json layer : layers) {
        std::string layerName = layer.value("type", "");
        if (layerName != "tilelayer") {
            continue;
        }
        
        nlohmann::json data = root.value("data", nlohmann::json());
        int index = 0;
        for (nlohmann::json cellData : data) {
            int typeIndex = cellData.get<int>();
            int row = index / blueprint.width;
            int column = index % blueprint.width;
            
            if (typeIndex == 0) {
                continue;
            }
            
            CellDataModel cell;
            cell.type = typeForIndex(typeIndex);
            cell.location = {column, row};
            blueprint.cells.push_back(cell);
        }
    }
    
    _allBlueprints.push_back(blueprint);
}

CellType BlueprintManager::typeForIndex(int index) {
    CellType cellType = Cell_None;
    switch (index) {
        case 0:
            cellType = Cell_None;
            break;
            
        case 1:
            cellType = Cell_Door;
            break;
            
        case 2:
            cellType = Cell_Wall;
            break;
            
        case 3:
            cellType = Cell_Window;
    }
    return cellType;
}

BlueprintDataModel BlueprintManager::getRandomBlueprint() {
    return _allBlueprints[0];
}
