#include "raylib.h"
#include "raygui.h"
#include "race_data.h"
#include "pages.h"
#include <string.h>

PageNum RaceSelect(struct Player *player) {
    static int optionSelected = 0;
	static int GoliathAncestrySelected = 0;
	static int lineageSelected = 0;
	static int GlineageSelected	= 0;
	static int typeSelected = 0;
	static int legacySelected = 0;
	static int traitSelected = 0;
    static bool dropOptionsActive = false; 
	static bool dropTypesActive = false;
	static bool dropLineageActive = false;
	static bool dropGLineageActive = false;
	static bool dropGTraitActive = false;
	static bool dropGoliathAncestryActive = false;
	static bool dropLegacyActive = false;
    const char *raceOptions = "Dragonborn;Dwarf;Elf;Gnome;Goliath;Halfling;Human;Orc;Tiefling";
	const char *dragonTypes = "Black;Blue;Brass;Bronze;Copper;Gold;Green;Red;Silver;White";
	const char *elvenLineages = "Drow;High Elf;Wood Elf";
	const char *gnomishLineages = "Forest Gnome;Rock Gnome";
	const char *gnomeTraits = "Intelligence;Wisdom;Charisma";
	const char *GoliathAncestry = "Cloud;Fire;Frost;Hill;Stone;Storm";
	const char *legacyOptions = "Abyssal;Chthonic;Infernal";

    GuiLabel((Rectangle){10, 15, 200, 20}, "Choose Option:");

    if (GuiButton((Rectangle){680, 750, 100, 30}, "Race info")) {
        return PAGE2;
    }

    if (GuiButton((Rectangle){220, 40, 115, 30}, "Confirm Race")) {
        switch (optionSelected) {
            case 0: 
				strcpy(player->Race, "Dragonborn");
				strcpy(player->Trait1, "Breath Weapon");
				strcpy(player->Trait2, "Damage Resistance");
				strcpy(player->Trait3, "Draconic Flight");
				player->Speed = 30;
				player->Darkvision = 60;
				break;
            case 1: 
				strcpy(player->Race, "Dwarf");
				strcpy(player->Trait1, "Dwarven Resilience");
				strcpy(player->Trait2, "Dwarven Toughness");
				strcpy(player->Trait3, "Stonecunning");
				player->Speed = 30;
				player->Darkvision = 120;
				break;
            case 2: 
				strcpy(player->Race, "Elf");
				strcpy(player->Trait1, "Fey Ancestry");
				strcpy(player->Trait2, "Keen Senses");
				strcpy(player->Trait2, "Trance");
				player->Speed = 30;
				player->Darkvision = 60;
				break;
			case 3: 
				strcpy(player->Race, "Gnome");
				strcpy(player->Trait1, "Gnomish Cunning");
				player->Speed = 30;
				player->Darkvision = 60;
				break;
            case 4: 
				strcpy(player->Race, "Goliath");
				strcpy(player->Trait1, "Large Form");
				strcpy(player->Trait2, "Powerful Build");
				player->Speed = 35;
				break;
            case 5: 
				strcpy(player->Race, "Halfling");
				strcpy(player->Trait1, "Brave");
				strcpy(player->Trait2, "Halfling Nimbleness");
				strcpy(player->Trait3, "Luck");
				strcpy(player->Trait4, "Naturally Stealthy");
				player->Speed = 30;
				break;
            case 6: 
				strcpy(player->Race, "Human");
				strcpy(player->Trait1, "Resourceful");
				strcpy(player->Trait2, "Skillful");
				strcpy(player->Trait3, "Versatile");
				player->Speed = 30;
				break;
            case 7: 
				strcpy(player->Race, "Orc");
				strcpy(player->Trait1, "Adrenaline Rush");
				strcpy(player->Trait2, "Relentless Endurance");
				player->Speed = 30;
				player->Darkvision = 120;
				break;
            case 8: 
				strcpy(player->Race, "Tiefling");
				strcpy(player->Trait1, "Otherworldly Presence");
				player->Speed = 30;
				player->Darkvision = 60;
				break;
        }
	strcpy(player->CreatureType, "Humanoid");	
    }
	

	if (strcmp(player->Race, "Dragonborn") == 0) {
		DrawText(TextFormat("Your lineage stems from a dragon progenitor.\nChoose the kind of dragon from the Draconic Ancestors table.\nYour choice affects your Breath Weapon,\nDamage Resistance traits, and your appearance."), 10, 175, 20, RAYWHITE);
		GuiLabel((Rectangle){10, 335, 200, 20}, "Choose Type:");
		if (GuiButton((Rectangle){220, 360, 115, 30}, " Confirm Type ")) { 
			switch (typeSelected) {
				case 0: 
					strcpy(player->DragonType, "Black");
					strcpy(player->DamageType, "Acid");
					break;
				case 1: 
					strcpy(player->DragonType, "Blue");
					strcpy(player->DamageType, "Lightning");
					break;
				case 2: 
					strcpy(player->DragonType, "Brass");
					strcpy(player->DamageType, "Fire");
					break;
				case 3: 
					strcpy(player->DragonType, "Bronze");
					strcpy(player->DamageType, "Lightning");
					break;
				case 4: 
					strcpy(player->DragonType, "Copper");
					strcpy(player->DamageType, "Acid");
					break;
				case 5: 
					strcpy(player->DragonType, "Gold");
					strcpy(player->DamageType, "Fire");
					break;
				case 6: 
					strcpy(player->DragonType, "Green");
					strcpy(player->DamageType, "Poison");
					break;
				case 7: 
					strcpy(player->DragonType, "Red");
					strcpy(player->DamageType, "Fire");
					break;
				case 8: 
					strcpy(player->DragonType, "Silver");
					strcpy(player->DamageType, "Cold");
					break;
				case 9: 
					strcpy(player->DragonType, "White");
					strcpy(player->DamageType, "Cold");
					break;
			}
		}
	DrawText(TextFormat("Type selected: %s", player->DragonType), 10, 410, 20, YELLOW);

	DrawText(TextFormat("Damage type: %s", player->DamageType), 10, 440, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){10, 360, 200, 30}, dragonTypes, &typeSelected, dropTypesActive)) {
		dropTypesActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 360, 200, 30})) {
		dropTypesActive = !dropTypesActive;
	}	
	}


	if (strcmp(player->Race, "Elf") == 0) {
		DrawText(TextFormat("You are part of a lineage that grants you supernatural abilities.\nChoose a lineage from the Elven Lineages table.\nYou gain the level 1 benefit of that lineage."), 10, 175, 20, RAYWHITE);
		GuiLabel((Rectangle){10, 335, 200, 20}, "Choose Lineage:");
		if (GuiButton((Rectangle){220, 360, 115, 30}, " Confirm Lineage ")) {
			switch (lineageSelected) {
				case 0: 
					strcpy(player->Lineage, "Drow");
					strcpy(player->LineageTrait, "Dancing Lights");
					break;
				case 1: 
					strcpy(player->Lineage, "High Elf");
					strcpy(player->LegacyCantrip, "Prestidigitation");
					break;
				case 2: 
					strcpy(player->Lineage, "Wood Elf");
					strcpy(player->LegacyCantrip, "Druidcraft");
					player->Speed = 35;
					break;
			}
		}

		
	DrawText(TextFormat("Lineage Selected: %s", player->Lineage), 10, 410, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){10, 360, 200, 30}, elvenLineages, &lineageSelected, dropLineageActive)) {
		dropLineageActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 360, 200, 30})) {
		dropLineageActive = !dropLineageActive;
	}
	}


	if (strcmp(player->Race, "Gnome") == 0) {
		DrawText(TextFormat("You are part of a lineage that grants you supernatural abilities.\nChoose a lineage from the Elven Lineages table.\nYou gain the level 1 benefit of that lineage."), 10, 175, 20, RAYWHITE);
		GuiLabel((Rectangle){10, 335, 200, 20}, "Choose Lineage:");
		if (GuiButton((Rectangle){220, 360, 115, 30}, " Confirm Lineage ")) {
			switch (lineageSelected) {
				case 0: 
					strcpy(player->Lineage, "Forest Gnome");
					break;
				case 1: 
					strcpy(player->Lineage, "Rock Gnome");
					break;
			}
		}
		GuiLabel((Rectangle){430, 335, 200, 20}, "Choose trait:");
		if (GuiButton((Rectangle){630, 360, 115, 30}, " Confirm trait ")) {
			switch (lineageSelected) {
				case 0: 
					strcpy(player->LineageTrait, "Intelligence");
					break;
				case 1: 
					strcpy(player->LineageTrait, "Wisdom");
					break;
				case 2:
					strcpy(player->LineageTrait, "Charisma");
					break;
			}
		}

	DrawText(TextFormat("Trait Selected: %s", player->LineageTrait), 430, 410, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){420, 360, 200, 30}, gnomeTraits, &traitSelected, dropGTraitActive)) {
		dropGTraitActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){420, 360, 200, 30})) {
		dropGTraitActive = !dropGTraitActive;
	}

	DrawText(TextFormat("Lineage Selected: %s", player->Lineage), 10, 410, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){10, 360, 200, 30}, gnomishLineages, &GlineageSelected, dropGLineageActive)) {
		dropGLineageActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 360, 200, 30})) {
		dropGLineageActive = !dropGLineageActive;
	}
	}


	if (strcmp(player->Race, "Goliath") == 0) {
		DrawText(TextFormat("You are descended from Giants.\nChoose Your Family line,\nand be blessed with a supernatural boon from your ancestry."), 10, 175, 20, RAYWHITE);
		GuiLabel((Rectangle){10, 335, 200, 20}, "Choose Ancestry:");
		if (GuiButton((Rectangle){220, 360, 115, 30}, " Confirm Ancestry ")) {
			switch (GoliathAncestrySelected) {
				case 0: 
					strcpy(player->GiantType, "Cloud Giant");
					strcpy(player->GiantBoon, "Cloud Jaunt");
					break;
				case 1: 
					strcpy(player->GiantType, "Fire Giant"); 
					strcpy(player->GiantBoon, "Fire Burn");
					break;
				case 2: 
					strcpy(player->GiantType, "Frost Giant");
					strcpy(player->GiantBoon, "Frost Chill");
					break;
				case 3: 
					strcpy(player->GiantType, "Hill Giant");
					strcpy(player->GiantBoon, "Hill Tumble");
					break;
				case 4: 
					strcpy(player->GiantType, "Stone Giant");
					strcpy(player->GiantBoon, "Stone Endrance");
					break;
				case 5:
					strcpy(player->GiantType, "Storm Giant"); 
					strcpy(player->GiantBoon, "Storm Thunder");
					break;
			}
		}

	DrawText(TextFormat("Ancestry Selected: %s", player->GiantType), 10, 410, 20, YELLOW);

	DrawText(TextFormat("Boon: %s", player->GiantBoon), 10, 440, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){10, 360, 200, 30}, GoliathAncestry, &GoliathAncestrySelected, dropGoliathAncestryActive)) {
		dropGoliathAncestryActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 360, 200, 30})) {
		dropGoliathAncestryActive = !dropGoliathAncestryActive;
	}
	}


	if (strcmp(player->Race, "Tiefling") == 0) {
		DrawText(TextFormat("You are the recipient of a legacy that grants you supernatural abilities.\nChoose a legacy from the Fiendish Legacies table."), 10, 175, 20, RAYWHITE);
		GuiLabel((Rectangle){10, 335, 200, 20}, "Choose Legacy:");
		if (GuiButton((Rectangle){220, 360, 115, 30}, " Confirm Legacy ")) {
			switch (legacySelected) {
				case 0: 
					strcpy(player->Legacy, "Abyssal");
					strcpy(player->LegacyCantrip, "Poison Spray");
					break;
				case 1: 
					strcpy(player->Legacy, "Chthonic"); 
					strcpy(player->LegacyCantrip, "Chill Touch");
					break;
				case 2: 
					strcpy(player->Legacy, "Infernal");
					strcpy(player->LegacyCantrip, "Fire Bolt");
					break;	
			}
		}

	DrawText(TextFormat("Legacy Selected: %s", player->Legacy), 10, 410, 20, YELLOW);

	DrawText(TextFormat("Legacy Cantrip: %s", player->LegacyCantrip), 10, 440, 20, YELLOW);

	if (GuiDropdownBox((Rectangle){10, 360, 200, 30}, legacyOptions, &legacySelected, dropLegacyActive)) {
		dropLegacyActive = false;
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
		CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 360, 200, 30})) {
		dropLegacyActive = !dropLegacyActive;
	}
	}


    DrawText(TextFormat("Option selected: %s", player->Race), 10, 90, 20, YELLOW);

    if (GuiDropdownBox((Rectangle){10, 40, 200, 30}, raceOptions, &optionSelected, dropOptionsActive)) {
        dropOptionsActive = false;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
        CheckCollisionPointRec(GetMousePosition(), (Rectangle){10, 40, 200, 30})) {
        dropOptionsActive = !dropOptionsActive;
    }

    return PAGE1;
}

