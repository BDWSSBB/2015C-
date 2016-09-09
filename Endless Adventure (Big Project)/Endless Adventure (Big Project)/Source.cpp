#include <iostream> // General note: The runner seems to hold about 75 characters per line.
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

void makeLower(string& userInput);
void helpDisplay(string userInput);
void playGame(string fighterClass, string userInput);
void statsChanged(int& playerLevel, int& experienceToLevelUp, int& maxPlayerHealth, int& maxPlayerMana, int& playerAttack, int& playerDefense, int& playerMagicAttack,
	int& playerMagicDefense, int& playerSpeed, double fighterAttributes[7], int equipmentBonus[7], double wellBonus[7], int helmetBonus[7],
	int chestplateBonus[7], int leggingsBonus[7], int bootsBonus[7]);
void warlockAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, int& enemyCurrentMana,
	double& enemyMagicAttackPowerModifier, bool& physicalOrMagic);
void ghostAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, int& enemyCurrentMana,
	double& enemyMagicAttackPowerModifier, bool& physicalOrMagic);
void bearAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, bool& physicalOrMagic);
void goblinAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, bool& physicalOrMagic);
void enemySpawnAndFight(string userInput, int& maxPlayerHealth, int& maxPlayerMana, int& playerAttack, int& playerDefense, int& playerMagicAttack,
	int& playerMagicDefense, int& playerSpeed, int& healthPotions, int& manaPotions, int playerSquare, int& currentHealth, int& currentMana,
	int& experience, int& experienceToLevelUp, int& goldAmount, int& tooManyEnemies);
void landmarkIsGeneralStore(string userInput, int& goldAmount, int& healthPotions, int& manaPotions, int playerSquare, int& tooManyEnemies);
void landmarkIsInn(string userInput, int& currentHealth, int maxPlayerHealth, int& currentMana, int maxPlayerMana, int& goldAmount, int playerSquare, int& tooManyEnemies);
void viewStats(int playerLevel, int experienceToLevelUp, int maxPlayerHealth, int maxPlayerMana, int playerAttack, int playerDefense, int playerMagicAttack,
	int playerMagicDefense, int playerSpeed, double fighterAttributes[7], int equipmentBonus[7], double wellBonus[7], int currentHealth, int currentMana, int experience,
	int goldAmount);

void helpDisplay(string userInput){ // Help menu.
	cout << endl << "You are a fighter in an endless adventure! Defeat as many monsters as possible." << endl;
	cout << "Level up and progress! Stop by shops and other landmarks! Defeat bosses!" << endl;
	while (true){
		cout << endl << "Would you like any explanation of anything?" << endl;
		cout << "[Stats]" << endl;
		cout << "[Enemies]" << endl;
		cout << "[Landmarks]" << endl;
		cout << "[Menu]" << endl;
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "stats"){ // Individual stat explanation.
			cout << endl << "Health: How much damage your fighter can take. When it reaches 0, you die!" << endl;
			cout << "Mana: Fuel to use magical attacks. When it reaches 0, you can't cast spells!" << endl;
			cout << "Attack: How much damage your fighter deals. It is reduced by enemy defense." << endl;
			cout << "Defense: How much damage you can resist. Does not reduce magic attack." << endl;
			cout << "Magic Attack: Apart from attack, magic attack pierces through defense." << endl;
			cout << "Magic Defense: Reduces magic attack instead of physical attack." << endl;
			cout << "Speed: How much you can dodge, as well as deciding who attacks first." << endl;
		}
		else if (userInput == "enemies"){ // Brief enemy explanation.
			cout << endl << "You will keep fighting random enemies. Defeat the enemy to proceed." << endl;
			cout << "You will always proceed in squares. Each square has a new enemy or landmark." << endl;
		}
		else if (userInput == "landmarks"){ // Landmark explanation.
			cout << endl << "There will always be a chance that the next square you go to has a landmark." << endl;
			cout << "Landmarks are safe areas for your fighter to rest or gear up." << endl;
			cout << "Some example of landmarks are general stores and inns." << endl;
		}
		else if (userInput == "menu"){ // Return to menu.
			return;
		}
		else{
			cout << endl << "Invalid selection." << endl;
		}
	}
}

void startGame(string userInput){ // Classes of fighters are selected here. This function also proceeds to the actual game.
	while (true){
		cout << endl << "Select a class." << endl;
		cout << "[Warrior]" << endl;
		cout << "[Mage]" << endl;
		cout << "[Thief]" << endl;
		cout << "[Menu]" << endl;
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "warrior"){
			cout << endl << "The warrior specializes in physical damage, using brute strength to kill." << endl;
		}
		else if (userInput == "mage"){
			cout << endl << "The mage uses magical abilities to aid in battle." << endl;
		}
		else if (userInput == "thief"){
			cout << endl << "The thief is fast and agile, usually able to gain the first strike." << endl;
		}
		else if (userInput == "menu"){
			break;
		}
		else{
			cout << endl << "Invalid selection." << endl;
			continue;
		}
		string fighterClass = userInput; // This is saved for the game if the player proceeds and is to explain each class if the user chooses so.
		while (true){
			cout << endl << "Would you like to play this class?" << endl;
			cout << "[Yes]" << endl;
			cout << "[No]" << endl;
			cout << "[More info]" << endl;
			getline(cin, userInput);
			makeLower(userInput);
			if (userInput == "yes"){ // Start the game!
				playGame(fighterClass, userInput);
				return; // Return to the main menu when the player dies.
			}
			else if (userInput == "no"){
				break;
			}
			else if (userInput == "more info"){
				if (fighterClass == "warrior"){
					cout << endl << "Health: 1.5x" << endl;
					cout << "Mana: 0.5x" << endl;
					cout << "Attack: 1.5x" << endl;
					cout << "Defense: 1.2x" << endl;
					cout << "Magic Attack: 0.5x" << endl;
					cout << "Magic Defense: 0.8x" << endl;
					cout << "Speed: 1.0x" << endl;
				}
				else if (fighterClass == "mage"){
					cout << endl << "Health: 0.8x" << endl;
					cout << "Mana: 2.0x" << endl;
					cout << "Attack: 0.5x" << endl;
					cout << "Defense: 1.0x" << endl;
					cout << "Magic Attack: 2.0x" << endl;
					cout << "Magic Defense: 1.2x" << endl;
					cout << "Speed: 1.0x" << endl;
				}
				else if (fighterClass == "thief"){
					cout << endl << "Health: 1.0x" << endl;
					cout << "Mana: 1.0x" << endl;
					cout << "Attack: 1.0x" << endl;
					cout << "Defense: 0.8x" << endl;
					cout << "Magic Attack: 1.0x" << endl;
					cout << "Magic Defense: 1.0x" << endl;
					cout << "Speed: 1.5x" << endl;
				}
			}
		}
	}
}

void playGame(string fighterClass, string userInput){
	double fighterAttributes[7]; // The actual player's fighter's attributes.
	if (fighterClass == "warrior"){ // This will change fighterAttributes into the class's actual attributes.
		double warriorAttributes[7]{1.5, 0.5, 1.5, 1.2, 0.5, 0.8, 1};
		for (int i = 0; i < 7; i++){
			fighterAttributes[i] = warriorAttributes[i];
		}
	}
	else if (fighterClass == "mage"){
		double mageAttributes[7]{0.8, 2, 0.5, 1, 2, 1.2, 1};
		for (int i = 0; i < 7; i++){
			fighterAttributes[i] = mageAttributes[i];
		}
	}
	else{
		double thiefAttributes[7]{1, 1, 1, 0.8, 1, 1, 1.5};
		for (int i = 0; i < 7; i++){
			fighterAttributes[i] = thiefAttributes[i];
		}
	}
	int playerLevel = 1; // All player data is supposed to be stored in this menu, while the stats viewer just displays them.
	int experience = 0;
	int currentHealth;
	int experienceToLevelUp = 0;
	int maxPlayerHealth = 0;
	int currentMana;
	int maxPlayerMana = 5;
	int playerAttack = 0;
	int playerDefense = 0;
	int playerMagicAttack = 0;
	int playerMagicDefense = 0;
	int playerSpeed = 0;
	string equipedHelmet = "None";
	int helmetBonus[7]{0, 0, 0, 0, 0, 0, 0};
	string equipedChestplate = "None";
	int chestplateBonus[7]{0, 0, 0, 0, 0, 0, 0};
	string equipedLeggings = "None";
	int leggingsBonus[7]{0, 0, 0, 0, 0, 0, 0};
	string equipedBoots = "None";
	int bootsBonus[7]{0, 0, 0, 0, 0, 0, 0};
	int equipmentBonus[7];
	double wellBonus[7]{1, 1, 1, 1, 1, 1, 1};
	int healthPotions = 0;
	int manaPotions = 0;
	statsChanged(playerLevel, experienceToLevelUp, maxPlayerHealth, maxPlayerMana, playerAttack, playerDefense, playerMagicAttack, playerMagicDefense,
		playerSpeed, fighterAttributes, equipmentBonus, wellBonus, helmetBonus, chestplateBonus, leggingsBonus, bootsBonus);
	currentHealth = maxPlayerHealth;
	currentMana = maxPlayerMana;

	int playerSquare = 1;
	int enemyOnSquareChance = 0; // Will use modulus and rand for chance. If there is not an enemy, there will be a landmark.
	int tooManyEnemies = 0; // The more enemies defeated without stopping by a landmark, the lower the chance an enemy will be on the next square.
	int landmarkTypeChance = 0; // 30% inn, 20% general store, 20% armory, 30% magical well.
	int goldAmount = 0; // Used for stores.

	cout << endl << "You have left the city of Valor to go on an endless adventure!" << endl;
	cout << "Out in the wild are some dangerous monsters. See how many you can defeat!" << endl;

	while (true){ //Actual gameplay begins.
		enemyOnSquareChance = rand() % 100;
		if (enemyOnSquareChance > 25 * tooManyEnemies){ // The chances are 100%, 75%, 50%, 25%, and 0%.
			enemySpawnAndFight(userInput, maxPlayerHealth, maxPlayerMana, playerAttack, playerDefense, playerMagicAttack, playerMagicDefense,
				playerSpeed, healthPotions, manaPotions, playerSquare, currentHealth, currentMana, experience, experienceToLevelUp, goldAmount, tooManyEnemies);
		}
		else{ // This means the player has gone to a landmark.
			landmarkTypeChance = rand() % 10;
			if (landmarkTypeChance >= 7){
				landmarkIsInn(userInput, currentHealth, maxPlayerHealth, currentMana, maxPlayerMana, goldAmount, playerSquare, tooManyEnemies);
			}
			else if (landmarkTypeChance >= 5){
				landmarkIsGeneralStore(userInput, goldAmount, healthPotions, manaPotions, playerSquare, tooManyEnemies);
			}
			else if (landmarkTypeChance >= 3){
				//landmarkIsArmory(); Will be implemented in future updates
				landmarkIsInn(userInput, currentHealth, maxPlayerHealth, currentMana, maxPlayerMana, goldAmount, playerSquare, tooManyEnemies);
			}
			else{
				//landmarkIsWell(); Will be implemented in future updates
				landmarkIsGeneralStore(userInput, goldAmount, healthPotions, manaPotions, playerSquare, tooManyEnemies);
			}
		}
		while (true){ //After defeating an enemy or exitting a landmark, this menu appears.
			if (currentHealth <= 0){
				return;
			}
			if (experience >= experienceToLevelUp){ // Check to see if the player has leveled up.
				experience = 0;
				playerLevel++;
				cout << "You have leveled up! You are now level " << playerLevel << "!" << endl;
				statsChanged(playerLevel, experienceToLevelUp, maxPlayerHealth, maxPlayerMana, playerAttack, playerDefense, playerMagicAttack, playerMagicDefense,
					playerSpeed, fighterAttributes, equipmentBonus, wellBonus, helmetBonus, chestplateBonus, leggingsBonus, bootsBonus);
				currentHealth = maxPlayerHealth;
				currentMana = maxPlayerMana;
			}
			cout << endl << "What would you like to do?" << endl;
			cout << "[Proceed]" << endl;
			//cout << "[View Items]" << endl;
			cout << "[View Stats]" << endl;
			getline(cin, userInput);
			makeLower(userInput);
			if (userInput == "proceed"){
				cout << "You carry on your adventure!" << endl;
				playerSquare++;
				break;
			}
			//else if (userInput == "view items"){
				// viewItems();
			//}
			else if (userInput == "view stats"){
				viewStats(playerLevel, experienceToLevelUp, maxPlayerHealth, maxPlayerMana, playerAttack, playerDefense, playerMagicAttack, playerMagicDefense,
					playerSpeed, fighterAttributes, equipmentBonus, wellBonus, currentHealth, currentMana, experience, goldAmount);
			}
			else{
				cout << "Invalid selection." << endl;
			}
		}
	}
}

void viewStats(int playerLevel, int experienceToLevelUp, int maxPlayerHealth, int maxPlayerMana, int playerAttack, int playerDefense, int playerMagicAttack,
	int playerMagicDefense, int playerSpeed, double fighterAttributes[7], int equipmentBonus[7], double wellBonus[7], int currentHealth, int currentMana, int experience,
	int goldAmount){
	cout << endl << "Level: " << playerLevel << endl;
	cout << "Experience: " << experience << "/" << experienceToLevelUp << endl;
	cout << "Health: " << currentHealth << "/" << maxPlayerHealth << endl;
	cout << "Mana: " << currentMana << "/" << maxPlayerMana << endl;
	cout << "Attack: " << playerAttack << endl;
	cout << "Defense: " << playerDefense << endl;
	cout << "Magic Attack: " << playerMagicAttack << endl;
	cout << "Magic Defense: " << playerMagicDefense << endl;
	cout << "Gold: " << goldAmount << endl;
}

void statsChanged(int& playerLevel, int& experienceToLevelUp, int& maxPlayerHealth, int& maxPlayerMana, int& playerAttack, int& playerDefense, int& playerMagicAttack,
	int& playerMagicDefense, int& playerSpeed, double fighterAttributes[7], int equipmentBonus[7], double wellBonus[7], int helmetBonus[7],
	int chestplateBonus[7], int leggingsBonus[7], int bootsBonus[7]){ // This function should be called when the player levels up.
	for (int i = 0; i < 7; i++){
		equipmentBonus[i] = helmetBonus[i] + chestplateBonus[i] + leggingsBonus[i] + bootsBonus[i];
	}
	experienceToLevelUp = 4 + pow(1.4, playerLevel);
	maxPlayerHealth = 20 * fighterAttributes[0] * wellBonus[0] * pow(1.3, playerLevel - 1) + equipmentBonus[0];
	maxPlayerMana = 10 * fighterAttributes[1] * wellBonus[1] + (playerLevel - 1) + equipmentBonus[1];
	playerAttack = 5 * fighterAttributes[2] * wellBonus[2] * pow(1.3, playerLevel - 1) + equipmentBonus[2];
	playerDefense = 2 * fighterAttributes[3] * wellBonus[3] * pow(1.3, playerLevel - 1) + equipmentBonus[3];
	playerMagicAttack = 5 * fighterAttributes[4] * wellBonus[4] * pow(1.3, playerLevel - 1) + equipmentBonus[4];
	playerMagicDefense = 2 * fighterAttributes[5] * wellBonus[5] * pow(1.3, playerLevel - 1) + equipmentBonus[5];
	playerSpeed = 10 * fighterAttributes[6] * wellBonus[6] + 2 * (playerLevel - 1) + equipmentBonus[6];
}

void enemySpawnAndFight(string userInput, int& maxPlayerHealth, int& maxPlayerMana, int& playerAttack, int& playerDefense, int& playerMagicAttack,
	int& playerMagicDefense, int& playerSpeed, int& healthPotions, int& manaPotions, int playerSquare, int& currentHealth, int& currentMana,
	int& experience, int& experienceToLevelUp, int& goldAmount, int& tooManyEnemies){
	int enemyChoice = rand() % 4;
	string enemyList[4]{"Goblin", "Bear", "Warlock", "Ghost"};
	string enemyFighting = enemyList[enemyChoice];
	double enemyAttributes[7]; // Enemy stats equated here.
	if (enemyFighting == "Goblin"){
		double enemyAttributes2[7]{1, 1, 1, 1, 1, 1, 1};
		for (int i = 0; i < 7; i++){
			enemyAttributes[i] = enemyAttributes2[i];
		}
	}
	else if (enemyFighting == "Bear"){
		double enemyAttributes2[7]{1.7, 1, 0.5, 1.3, 1, 0.7, 0.6};
		for (int i = 0; i < 7; i++){
			enemyAttributes[i] = enemyAttributes2[i];
		}
	}
	else if (enemyFighting == "Warlock"){
		double enemyAttributes2[7]{0.7, 2, 0.5, 0.8, 1.5, 1.2, 1};
		for (int i = 0; i < 7; i++){
			enemyAttributes[i] = enemyAttributes2[i];
		}
	}
	else{ // Ghost Attributes
		double enemyAttributes2[7]{1, 1, 1, 1, 0.5, 1.5, 1.2};
		for (int i = 0; i < 7; i++){
			enemyAttributes[i] = enemyAttributes2[i];
		}
	}
	int enemyHealth = 5 * pow(1.1, playerSquare) * enemyAttributes[0] + 1;
	int enemyCurrentHealth = enemyHealth;
	int enemyMana = 5 + 0.2 * playerSquare * enemyAttributes[1] + 1;
	int enemyCurrentMana = enemyMana;
	string enemyAttackDetail; // This is carried onto each monster AI so the details of their attacks are carried on.
	double enemyAttackPowerModifier = 0; // Based on what kind of attack, this will multiply the value.
	int enemyAttackChanceModifier; //100 = 100% chance (default)
	int enemyAttack = 3 * pow(1.1, playerSquare) * enemyAttributes[2] + 1;
	int playerDamageTaken = 0;
	int enemyDamageTaken = 0;
	int enemyDefense = pow(1.1, playerSquare) * enemyAttributes[3] + 1;
	double enemyMagicAttackPowerModifier = 0;
	int enemyMagicAttack = 3 * pow(1.1, playerSquare) * enemyAttributes[4] + 1;
	int enemyMagicDefense = pow(1.1, playerSquare) * enemyAttributes[5] + 1;
	int enemySpeed = (9 + 2 * playerSquare) * enemyAttributes[6] + 1;
	bool physicalOrMagic = false; // false = phsyical, true = magic.
	int goldDropped = 3 * pow(1.1, playerSquare);
	int experienceGained = 3 + pow(1.15, playerSquare);

	cout << endl << "You encounter a " << enemyFighting << "!" << endl;
	if (playerSpeed < enemySpeed){
		if (enemyFighting == "Goblin"){
			goblinAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, physicalOrMagic);
		}
		else if (enemyFighting == "Bear"){
			bearAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, physicalOrMagic);
		}
		else if (enemyFighting == "Warlock"){
			warlockAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, enemyCurrentMana, enemyMagicAttackPowerModifier,
				physicalOrMagic);
		}
		else{
			ghostAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, enemyCurrentMana, enemyMagicAttackPowerModifier,
				physicalOrMagic);
		}
		cout << endl << enemyAttackDetail << endl;
		if (rand() % 100 * enemyAttackChanceModifier * enemySpeed / playerSpeed < 100){
			if (physicalOrMagic == false){ // Player took physical damage.
				if (enemyAttack * enemyAttackPowerModifier < playerDefense / 2 - 1){
					playerDamageTaken = 1;
				}
				else{
					playerDamageTaken = enemyAttack * enemyAttackPowerModifier - playerDefense / 2;
				}
			}
			else{ // Player took magic damage.
				if (enemyMagicAttack * enemyMagicAttackPowerModifier < playerMagicDefense / 2 - 1){
					playerDamageTaken = 1;
				}
				else{
					playerDamageTaken = enemyMagicAttack * enemyMagicAttackPowerModifier - playerMagicDefense / 2;
				}
			}
			cout << "You took " << playerDamageTaken << " damage!" << endl;
			currentHealth -= playerDamageTaken;
			if (currentHealth <= 0){
				cout << "You died!" << endl;
				return;
			}
		}
		else{
			cout << enemyFighting << " missed!" << endl;
		}
	}
	while (true){
		cout << endl << "Health: " << currentHealth << "/" << maxPlayerHealth << endl;
		cout << "Mana: " << currentMana << "/" << maxPlayerMana << endl;
		cout << "Enemy Health: " << enemyCurrentHealth << "/" << enemyHealth << endl;
		cout << "Health potions: " << healthPotions << endl;
		cout << "Mana potions: " << manaPotions << endl << endl;
		cout << "What do you want to do?" << endl;
		cout << "[Attack]" << endl;
		cout << "[Magic]" << endl;
		cout << "[Use Health Potion]" << endl;
		cout << "[Use Mana Potion]" << endl;
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "attack") {
			if (playerAttack < enemyDefense / 2 - 1){ // Minimum damage possible is 1.
				enemyCurrentHealth--;
				cout << endl << enemyFighting << " took 1 damage!" << endl;
			}
			else{
				enemyDamageTaken = playerAttack - enemyDefense / 2;
				enemyCurrentHealth -= enemyDamageTaken;
				cout << endl << enemyFighting << " took " << enemyDamageTaken << " damage!" << endl;
			}
		}
		else if (userInput == "magic"){
			if (currentMana >= 3){
				currentMana -= 3;
				if (playerMagicAttack < enemyMagicDefense / 2 - 1){ // Minimum damage is 1.
					enemyCurrentHealth--;
					cout << endl << enemyFighting << " took 1 damage!" << endl;
				}
				else{
					enemyDamageTaken = playerMagicAttack - enemyMagicDefense / 2;
					enemyCurrentHealth -= enemyDamageTaken;
					cout << endl << enemyFighting << " took " << enemyDamageTaken << " damage!" << endl;
				}
			}
			else{
				cout << endl << "You do not have enough mana to use magic attacks!" << endl;
				continue;
			}
		}
		else if (userInput == "use health potion"){
			if (healthPotions < 1){
				cout << "You do not have any health potions!" << endl;
				continue;
			}
			else{
				cout << "You use a health potion!" << endl;
				currentHealth = maxPlayerHealth;
			}
		}
		else if (userInput == "use mana potion"){
			if (manaPotions < 1){
				cout << "You do not have any mana potions!" << endl;
				continue;
			}
			else{
				cout << "You use a mana potion!" << endl;
				currentMana = maxPlayerMana;
			}
		}
		else{
			cout << "Invalid selection." << endl;
			continue;
		}
		if (enemyCurrentHealth <= 0){ // Check to see if the monster is dead.
			cout << endl << enemyFighting << " has been defeated!" << endl;
			goldAmount += goldDropped;
			cout << "You got " << goldDropped << " gold!" << endl;
			experience += experienceGained;
			cout << "You got " << experienceGained << " experience!" << endl;
			tooManyEnemies++;
			return;
		}
		else{ // Enemy attacks, player and enemy attacks loop until one of them dies.
			if (enemyFighting == "Goblin"){
				goblinAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, physicalOrMagic);
			}
			else if (enemyFighting == "Bear"){
				bearAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, physicalOrMagic);
			}
			else if (enemyFighting == "Warlock"){
				warlockAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, enemyCurrentMana, enemyMagicAttackPowerModifier,
					physicalOrMagic);
			}
			else{
				ghostAI(enemyAttackDetail, enemyAttackPowerModifier, enemyAttackChanceModifier, enemyCurrentMana, enemyMagicAttackPowerModifier,
					physicalOrMagic);
			}
			cout << endl << enemyAttackDetail << endl;
			if (rand() % 100 * enemyAttackChanceModifier * enemySpeed / playerSpeed < 100){
				if (physicalOrMagic == false){ // Player took physical damage.
					if (enemyAttack * enemyAttackPowerModifier < playerDefense / 2 - 1){
						playerDamageTaken = 1;
					}
					else{
						playerDamageTaken = enemyAttack * enemyAttackPowerModifier - playerDefense / 2;
					}
				}
				else{ // Player took magic damage.
					if (enemyMagicAttack * enemyMagicAttackPowerModifier < playerMagicDefense / 2 - 1){
						playerDamageTaken = 1;
					}
					else{
						playerDamageTaken = enemyMagicAttack * enemyMagicAttackPowerModifier - playerMagicDefense / 2;
					}
				}
				cout << "You took " << playerDamageTaken << " damage!" << endl;
				currentHealth -= playerDamageTaken;
				if (currentHealth <= 0){
					cout << "You died!" << endl;
					return;
				}
			}
			else{
				cout << enemyFighting << " missed!" << endl;
			}
		}
	}
}

void goblinAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, bool& physicalOrMagic){
	int enemyAttackChoice = rand() % 3;
	if (enemyAttackChoice == 0){ // Light Attack
		enemyAttackDetail = "The goblin gives a quick strike with its axe!";
		enemyAttackPowerModifier = 0.5;
		enemyAttackChanceModifier = 2;
		physicalOrMagic = false;
	}
	else if (enemyAttackChoice == 1){ // Normal Attack
		enemyAttackDetail = "The goblin cleaves with force!";
		enemyAttackPowerModifier = 1;
		enemyAttackChanceModifier = 1;
		physicalOrMagic = false;
	}
	else{ // Heavy Attack
		enemyAttackDetail = "The goblin charges up a blow!";
		enemyAttackPowerModifier = 2;
		enemyAttackChanceModifier = 0.5;
		physicalOrMagic = false;
	}
}

void ghostAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, int& enemyCurrentMana,
	double& enemyMagicAttackPowerModifier, bool& physicalOrMagic) {
	int enemyAttackChoice = rand() % 3;
	if (enemyAttackChoice == 0){ // Super Light Attack
		enemyAttackDetail = "The ghost frightens you with a scream!";
		enemyAttackPowerModifier = 0.2;
		enemyAttackChanceModifier = 90;
		physicalOrMagic = false;
	}
	else if (enemyAttackChoice == 1 && enemyCurrentMana >= 3){ // Magic Attack
		enemyCurrentMana -= 3;
		enemyAttackDetail = "The ghost ignites you with a cursed flame!";
		enemyMagicAttackPowerModifier = 1.2;
		enemyAttackChanceModifier = 1;
		bool physicalOrMagic = true;
	}
	else{ // Normal Attack
		enemyAttackDetail = "The ghost hurls a chair towards you!";
		enemyAttackPowerModifier = 1;
		enemyAttackChanceModifier = 0.5;
		physicalOrMagic = false;
	}
}

void bearAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, bool& physicalOrMagic){
	int enemyAttackChoice = rand() % 3;
	if (enemyAttackChoice == 0){ // Light Attack
		enemyAttackDetail = "The bear quickly swipes with its paw!";
		enemyAttackPowerModifier = 0.5;
		enemyAttackChanceModifier = 2;
		physicalOrMagic = false;
	}
	else if (enemyAttackChoice == 1){ // Normal Attack
		enemyAttackDetail = "The bear lashs a bite!";
		enemyAttackPowerModifier = 1;
		enemyAttackChanceModifier = 1;
		physicalOrMagic = false;
	}
	else{ // Heavy Attack
		enemyAttackDetail = "The bear charges to flatten you!";
		enemyAttackPowerModifier = 2;
		enemyAttackChanceModifier = 0.5;
		physicalOrMagic = false;
	}
}

void warlockAI(string& enemyAttackDetail, double& enemyAttackPowerModifier, int& enemyAttackChanceModifier, int& enemyCurrentMana,
	double& enemyMagicAttackPowerModifier, bool& physicalOrMagic){
	if (enemyCurrentMana >= 3){
		enemyCurrentMana -= 3;
		int enemyAttackChoice = rand() % 3;
		if (enemyAttackChoice == 0){ // Light Attack
			enemyAttackDetail = "The warlock flicks a small ball of ice!";
			enemyMagicAttackPowerModifier = 0.5;
			enemyAttackChanceModifier = 2;
			bool physicalOrMagic = true;
		}
		else if (enemyAttackChoice == 1){ // Normal Attack
			enemyAttackDetail = "The warlock casts a fireball!";
			enemyMagicAttackPowerModifier = 1;
			enemyAttackChanceModifier = 1;
			bool physicalOrMagic = true;
		}
		else{ // Heavy Attack
			enemyAttackDetail = "The warlock conjures a ball of darkness!";
			enemyMagicAttackPowerModifier = 2;
			enemyAttackChanceModifier = 0.5;
			bool physicalOrMagic = true;
		}
	}
	else{
		enemyAttackDetail = "The warlock smacks you with his stick!";
		enemyAttackPowerModifier = 0.3;
		enemyAttackChanceModifier = 1;
		physicalOrMagic = false;
	}
}

void landmarkIsInn(string userInput, int& currentHealth, int maxPlayerHealth, int& currentMana, int maxPlayerMana, int& goldAmount, int playerSquare, int& tooManyEnemies){
	tooManyEnemies = 0;
	int innCost = 5 * pow(1.1, playerSquare);
	cout << endl << "You stop by an inn. You can rest to recover your health and mana." << endl;
	while (true){
		cout << "It costs " << innCost << " gold to rest here. You have " << goldAmount << " gold. Would you like to rest?" << endl;
		cout << "[Yes]" << endl;
		cout << "[No]" << endl;
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "yes"){
			if (goldAmount >= innCost){
				goldAmount -= innCost;
				currentHealth = maxPlayerHealth;
				currentMana = maxPlayerMana;
				cout << endl << "After a day in the inn, you feel refreshed! Your health and mana is refilled." << endl;
				cout << "You leave happily." << endl;
				return;
			}
			else{
				cout << endl << "You do not have enough gold to stay in." << endl;
				cout << "You will have to continue without resting." << endl;
				return;
			}
		}
		else if (userInput == "no"){
			cout << endl << "You decide to continue on your adventure without resting." << endl;
			return;
		}
		else{
			cout << endl << "Invalid response." << endl;
			continue;
		}
	}
}

void landmarkIsGeneralStore(string userInput, int& goldAmount, int& healthPotions, int& manaPotions, int playerSquare, int& tooManyEnemies){
	tooManyEnemies = 0;
	int healthPotionStock = (rand() % 4) + 1;
	int manaPotionStock = (rand() % 4) + 1;
	int healthPotionCost = 5 * pow(1.1, playerSquare);
	int manaPotionCost = 3 * pow(1.1, playerSquare);
	cout << endl << "You stop by a general store. They have health and mana potions for sale." << endl;
	while (true){
		cout << endl << "Health potions cost " << healthPotionCost << " gold. " << healthPotionStock << " are on stock." << endl;
		cout << "Mana potions cost " << manaPotionCost << " gold. " << manaPotionStock << " are on stock." << endl;
		cout << "You have " << goldAmount << " gold. Would you like to buy anything? " << endl;
		cout << "[Buy Health Potion]" << endl;
		cout << "[Buy Mana Potion]" << endl;
		cout << "[Leave]" << endl;
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "buy health potion"){
			if (goldAmount >= healthPotionCost && healthPotionStock >= 1){
				goldAmount -= healthPotionCost;
				healthPotions++;
				healthPotionStock--;
				cout << endl << "You purchase a health potion." << endl;
				continue;
			}
			else if (healthPotionStock <= 0){
				cout << endl << "There are no health potions available." << endl;
				continue;
			}
			else{
				cout << endl << "You do not have enough gold." << endl;
				continue;
			}
		}
		else if (userInput == "buy mana potion"){
			if (goldAmount >= manaPotionCost && manaPotionStock >= 1){
				goldAmount -= manaPotionCost;
				manaPotions++;
				manaPotionStock--;
				cout << endl << "You purchase a mana potion." << endl;
				continue;
			}
			else if (manaPotionStock <= 0){
				cout << endl << "There are no mana potions available." << endl;
				continue;
			}
			else{
				cout << endl << "You do not have enough gold." << endl;
				continue;
			}
		}
		else if (userInput == "leave"){
			cout << endl << "You leave the general store." << endl;
			return;
		}
		else{
			cout << endl << "Invalid response." << endl;
			return;
		}
	}
}

void landmarkIsArmory(){
	cout << endl << "In progress." << endl;
	return;
}

void landmarkIsWell(){
	cout << endl << "In progress." << endl;
	return;
}

int main(){
	srand(time(NULL));

	while (true){ // Main Menu.
		cout << endl << "Welcome to Endless Adventure! Select an option." << endl;
		cout << "[Play]" << endl;
		cout << "[Help]" << endl;
		cout << "[Quit]" << endl;
		string userInput; // This will be how the player selects their options.
		getline(cin, userInput);
		makeLower(userInput);
		if (userInput == "play"){
			startGame(userInput);
		}
		else if (userInput == "help"){
			helpDisplay(userInput);
		}
		else if (userInput == "quit"){
			break;
		}
		else{
			cout << endl << "Invalid response." << endl;
		}
	}
	system("PAUSE");
	return 0;
}

void makeLower(string& userInput){ // Automatically makes the user's inputs in lower case.
	for (int i = 0; i < userInput.length(); i++) {
		userInput[i] = tolower(userInput[i]);
	}
}