#include <iostream> 
#include <string>   
#include <cmath>
#include <cstdlib>
#include <algorithm> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/utsname.h>

#define MAX_INPUT 1024

// --- ENUM CLASS for Type-Safe Status Reporting (RESOLUTIONENGINE V9) ---
enum class ResolutionStatus {
    WORKED_ANYWAY, IMPOSSIBLE_ERROR, GOOSE_PACIFIED_PRINGLES, GOOSE_PACIFIED_FORCE,
    REALITY_MENDED, SMILE_RESTORED, TAPED_INTO_SUBMISSION, EFFICIENTLY_HONKED,
    POEM_GENERATED, THANOS_CURED, BURNTRAP_QUENCHED, POWER_GENERATED,
    BEELZEBUB_AVOIDED, MISSINGNO_JOKE,
    CRUSTACEAN_PROCESSED,
    SECURITY_DOOR_SLAMMED, // V9 Addition (from first version)
    AFTON_CONTAINED        // V9 Addition (from first version)
};

// Helper function to convert the enum to a printable string
std::string statusToString(ResolutionStatus status) {
    switch (status) {
        case ResolutionStatus::SECURITY_DOOR_SLAMMED: return "SECURITY_DOOR_SLAMMED (Power Drain: HIGH)";
        case ResolutionStatus::AFTON_CONTAINED: return "AFTON_CONTAINED (Countermeasures Deployed)";
        case ResolutionStatus::WORKED_ANYWAY: return "WORKED_ANYWAY";
        case ResolutionStatus::IMPOSSIBLE_ERROR: return "IMPOSSIBLE_ERROR";
        case ResolutionStatus::GOOSE_PACIFIED_PRINGLES: return "GOOSE_PACIFIED_PRINGLES (Pringles Used)";
        case ResolutionStatus::GOOSE_PACIFIED_FORCE: return "GOOSE_PACIFIED_FORCE (Resources Allocated)";
        case ResolutionStatus::REALITY_MENDED: return "REALITY_MENDED (Physics Bended)";
        case ResolutionStatus::SMILE_RESTORED: return "SMILE_RESTORED (JUMPSCARE Protocol)";
        case ResolutionStatus::TAPED_INTO_SUBMISSION: return "TAPED_INTO_SUBMISSION (Duct Tape Fix)";
        case ResolutionStatus::EFFICIENTLY_HONKED: return "EFFICIENTLY_HONKED (Default Fallback)";
        case ResolutionStatus::POEM_GENERATED: return "POEM_GENERATED (Logic Overload, Royalties Paid)";
        case ResolutionStatus::THANOS_CURED: return "THANOS_CURED (Gamma Protocol)";
        case ResolutionStatus::BURNTRAP_QUENCHED: return "BURNTRAP_QUENCHED (Thirst Mitigated)";
        case ResolutionStatus::POWER_GENERATED: return "POWER_GENERATED (7 Trillion Petawatts)";
        case ResolutionStatus::BEELZEBUB_AVOIDED: return "BEELZEBUB_AVOIDED (Left the Backrooms)";
        case ResolutionStatus::MISSINGNO_JOKE: return "MISSINGNO_JOKE (Pokechu Protocol)";
        case ResolutionStatus::CRUSTACEAN_PROCESSED: return "CRUSTACEAN_PROCESSED (Seafood Optimized)"; 
        default: return "UNKNOWN_STATUS";
    }
}


class ResolutionEngine {
private:
    // --- CORE STATE & INVARIANTS (V8 BASE) ---
    const int GLITTER_LEVEL_ = 100;
    const double REALITY_TOLERANCE_ = 0.5;
    const int MAX_PRINGLES_TOLERANCE_ = 15;
    
    double willpowerGauge_;
    int tapeReserve_ = 50; 
    bool isDawnSmiling_ = true;
    int PRINGLES_;                        
    double MARKIPLIER_X_FNAF_;         
    bool JUMPSCARE_ = false;                  
    int POOTISHEAVY_TF2_;               
    int NOTEBOOK_ = 0;                        
    int MEMES_ = 10;
    double FUNNI_ = 50.0;
    int gooseRoyalties_ = 0; 
    
    // --- V8 BIOLOGICAL/CULINARY VARIABLES ---
    int SHRIMP_COUNT_ = 10;          
    int BREAD_QUALITY_ = 75;         
    bool FISH_STATUS_ = true;        

    // --- V9 FNAF/SECURITY VARIABLES (FROM FIRST VERSION) ---
    int FREDDY_STRENGTH_ = 80;        
    double PIZZA_GREASE_ = 0.35;      
    int POWER_LEFT_ = 1000;                      
    std::string WILLIAM_AFTON_STATE_ = "PATROL"; 
    const std::string MICHAEL_AFTON_ = "Michael Afton"; 
    const std::string HENRY_EMILY_ = "Henry Emily";     
    // ------------------------------------------


    // --- HELPER METHODS (V9 ADDITIONS) ---
    void tapeOver(const std::string& problem) { std::cout << "Taping over " << problem << std::endl; }
    
    // Power-consuming action
    void securityDoorSlam() {
        const int POWER_COST = 350;
        if (POWER_LEFT_ >= POWER_COST) {
            std::cout << "\n[FNAF SECURITY PROTOCOL]: Animatroic detected! Slamming security door! (Power Cost: " << POWER_COST << ")" << std::endl;
            POWER_LEFT_ -= POWER_COST;
            FREDDY_STRENGTH_ = std::max(0, FREDDY_STRENGTH_ - 10);
            willpowerGauge_ = std::min(willpowerGauge_ + 5.0, 100.0);
            this->tapeOver("security door seal"); 
        } else {
            std::cout << "\n[FNAF SECURITY ALERT]: Power too low! Door failed to slam. (Power Left: " << POWER_LEFT_ << ")" << std::endl;
        }
    }
    
    // Afton Counter-Protocol Logic
    void deployAftonCountermeasures() {
        std::cout << "\n[AFTON PROTOCOL]: William Afton is in state: MURDER. Initiating containment." << std::endl;
        
        std::cout << "   -> Deploying " << MICHAEL_AFTON_ << " (Investigator). Afton's location compromised." << std::endl;
        std::cout << "   -> Deploying " << HENRY_EMILY_ << " (Strategist). Containment plan active." << std::endl;
        
        WILLIAM_AFTON_STATE_ = "RETREATED";
        FREDDY_STRENGTH_ = std::max(0, FREDDY_STRENGTH_ - 50);
        POWER_LEFT_ += 100; // Containment is efficient!
        willpowerGauge_ += 25.0;
        std::cout << "   -> William Afton state changed to: RETREATED." << std::endl;
    }
    
    // --- HELPER METHODS (V8 BASE) ---
    void gooseLoudly() { printf("HONK! (Problem acknowledged.)\n"); }
    void efficientize(const std::string& process) { std::cout << "EFFICIENTIZING: Removing steps from " << process << std::endl; }
    void undoCommonSense() { std::cout << "Common Sense Disabled." << std::endl; }
    void processSeafood() {
        // ... (V8 logic omitted for brevity, but retained its core function) ...
        SHRIMP_COUNT_ = 0; FUNNI_ = std::min(FUNNI_ + 45.0, 100.0); willpowerGauge_ += 15.0;
    }
    // Note: dawnProtect() and generatePoem() omitted for brevity in the helpers section, but assumed available.


public:
    // --- CONSTRUCTOR ---
    ResolutionEngine(int initialPringles, double stabilityConstant, double initialWillpower, int initialPootis)
        : PRINGLES_(initialPringles), MARKIPLIER_X_FNAF_(stabilityConstant), willpowerGauge_(initialWillpower), POOTISHEAVY_TF2_(initialPootis) {
        std::srand(std::time(0)); 
    }
    
    // --- ACCESSOR METHODS ---
    int getPringles() const { return PRINGLES_; }
    double getFunniLevel() const { return FUNNI_; }
    int getGooseRoyalties() const { return gooseRoyalties_; }
    int getFreddyStrength() const { return FREDDY_STRENGTH_; } 
    int getPowerLeft() const { return POWER_LEFT_; } 
    std::string getAftonState() const { return WILLIAM_AFTON_STATE_; }
    int getShrimpCount() const { return SHRIMP_COUNT_; }
    int getBreadQuality() const { return BREAD_QUALITY_; } 
    
    // --- THE MAIN RESOLUTION FUNCTION (Public API - V9 Logic Priority) ---
    ResolutionStatus resolveProblem(const std::string& problem) {
        
        // V9 HIGH PRIORITY: AFTON PROTOCOL (Check first)
        if (problem.find("purple guy") != std::string::npos || problem.find("children") != std::string::npos) {
            WILLIAM_AFTON_STATE_ = "MURDER";
        }
        if (WILLIAM_AFTON_STATE_ == "MURDER") {
            this->deployAftonCountermeasures();
            return ResolutionStatus::AFTON_CONTAINED;
        }

        // V9 SECOND PRIORITY: FNAF/SECURITY PROTOCOL
        if (problem.find("animatronic") != std::string::npos || problem.find("power outage") != std::string::npos) {
            this->securityDoorSlam(); 
            return ResolutionStatus::SECURITY_DOOR_SLAMMED;
        }

        // V9 JUMPSCARE/SMILE PROTOCOL (Blends FNAF and V8 logic)
        if (problem.find("sadness") != std::string::npos || problem.find("low sparkle") != std::string::npos) {
            JUMPSCARE_ = true;
            if (FREDDY_STRENGTH_ < 50 && willpowerGauge_ > 50.0) { 
                // Restore smile logic (V8/V5)
                return ResolutionStatus::SMILE_RESTORED;
            } else if (FREDDY_STRENGTH_ >= 50) {
                 std::cout << "[JUMPSCARE FAILURE]: Freddy is too strong! Initiating security protocol." << std::endl;
                 this->securityDoorSlam();
                 return ResolutionStatus::SECURITY_DOOR_SLAMMED;
            }
        }

        // V8 HIGH PRIORITY: Seafood/Crustacean Logic
        if (problem.find("shrimp") != std::string::npos || problem.find("fish") != std::string::npos) {
            this->processSeafood();
            return ResolutionStatus::CRUSTACEAN_PROCESSED;
        }

        // V8/V5 CORE LOGIC: GOOSE & HONK LOGIC
        if (problem.find("goose") != std::string::npos || problem.find("bread shortage") != std::string::npos) {
            if (BREAD_QUALITY_ >= 50) {
                // ... (V8 Bread logic) ...
                return ResolutionStatus::GOOSE_PACIFIED_FORCE; 
            }
            if (PRINGLES_ > 0) {
                // ... (V8 Pringle logic) ...
                return ResolutionStatus::GOOSE_PACIFIED_PRINGLES;
            }
        }
        
        // DEFAULT & EFFICIENCY BLOCK
        this->efficientize(problem); this->undoCommonSense(); this->gooseLoudly();
        return ResolutionStatus::EFFICIENTLY_HONKED;
    }
};

// --- GLOBAL INSTANCE (SD/OS will access this) ---
ResolutionEngine henryEngine(5, 0.75, 99.9, 10000); 
//-------------------------------------------------


// C Global variable
int goose_enabled = 0;

// Forward declarations for the C functions (All C shell commands)
void splash_screen();
void display_sysinfo();
void help();
// ... (omitted placeholder function declarations) ...
void parseCommand(char *input);
void honk() {
    printf("\a"); 
    printf("    __\n");
    printf("__(o )>\n");
    printf("\\ <_. )   🦆 HONK!\n");
    printf(" `---'\n");
    printf("[SD/OS ALERT] Goose Mode Engaged.\n");
}
void uname_cmd() {
    printf("SD/OS Chaos Core V9.0 (FNAF/Afton & Bio-Culinary Certified)\n");
    printf("Kernel Interface API Layer: Stable\n");
}

// --- Shell Functions (C code) ---

void splash_screen() {
    printf("==============================================\n");
    printf("         SD/OS Chaos Core V9.0 \n"); // VERSION CHANGE
    printf("          FNAF/Afton Counter-Protocol Active\n");
    printf("          Architecture: UNIX Environment\n");
    printf("==============================================\n");
    printf("Initializing kernel interface...\n");
    sleep(1);
    printf("[✓] Filesystem ready\n");
    usleep(500000);
    printf("[✓] Process manager online\n");
    usleep(500000);
    printf(">> Launching SD/OS Shell...\n");
    sleep(1);
    printf("==============================================\n\n");
}

void display_sysinfo() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    struct utsname sys;
    uname(&sys);

    printf("SYSTEM INFORMATION\n");
    printf("------------------\n");
    printf("Time: %s", asctime(t));
    printf("System: %s %s (%s)\n", sys.sysname, sys.release, sys.machine);
    printf("Chaos Engine Core Status: (Pringles: %d, Funni: %.1f%%, Royalties: %d)\n", 
           henryEngine.getPringles(), henryEngine.getFunniLevel(), henryEngine.getGooseRoyalties()); 
    printf("Chaos Engine FNAF Status: (Freddy Strength: %d, Power Left: %d, Afton: %s)\n", 
           henryEngine.getFreddyStrength(), henryEngine.getPowerLeft(), henryEngine.getAftonState().c_str());
    printf("Chaos Engine Bio-Culinary Status: (Shrimp: %d, Bread Quality: %d%%)\n",
           henryEngine.getShrimpCount(), henryEngine.getBreadQuality());
    printf("SD/OS Shell Ready. Type `help` to begin.\n\n");
}

void help() {
    printf("SD/OS Command List:\n");
    // ... (omitted shell commands) ...
    printf("\n--- CHAOS CORE COMMANDS V9 ---\n"); // VERSION CHANGE
    printf("  resolve <prob>  - Pass a problem to the Resolution Engine (e.g., resolve purple guy, resolve animatronic, resolve shrimp)\n");
    printf("  engine status   - Display current state of the Chaos Engine\n");
}

// Minimal placeholder implementations for required C functions
void dir() { printf("Placeholder: Listing directory contents...\n"); }
void cd(char *path) { if (path) printf("Placeholder: Changing directory to %s\n", path); }
void tasks() { printf("Placeholder: Showing running tasks...\n"); }
void cls() { printf("\033[H\033[J"); }
void shutdown_cmd() { printf("Placeholder: System shutdown initiated. Goodbye.\n"); exit(0); }
void restart() { printf("Placeholder: Restarting SD/OS Shell...\n"); }
void copy(char *src, char *dest) { if (src && dest) printf("Placeholder: Copying %s to %s\n", src, dest); }
void del(char *file) { if (file) printf("Placeholder: Deleting %s\n", file); }
void mkdir_cmd(char *dir) { if (dir) printf("Placeholder: Creating directory %s\n", dir); }
void rmdir_cmd(char *dir) { if (dir) printf("Placeholder: Removing directory %s\n", dir); }
void type(char *file) { if (file) printf("Placeholder: Viewing file %s contents...\n", file); }
void ren(char *oldname, char *newname) { if (oldname && newname) printf("Placeholder: Renaming %s to %s\n", oldname, newname); }

void parseCommand(char *input) {
    char *input_copy = strdup(input); 
    char *cmd_token = strtok(input_copy, " ");
    if (!cmd_token) {
        free(input_copy);
        return;
    }
    
    std::string cmd = cmd_token;

    // Easter egg activation
    if (strcmp(input, "activate --egg=obscure42") == 0) {
        goose_enabled = 1;
        printf("[SD/OS] Goose Mode activated. Proceed with caution.\n");
        free(input_copy);
        return;
    }

    // --- C++ Engine Integration ---
    if (cmd == "resolve") {
        const char *problem_start = strstr(input, "resolve ");
        if (!problem_start) {
             printf("[SD/OS CHAOS] Usage: resolve <problem description>\n");
             free(input_copy);
             return;
        }
        problem_start += strlen("resolve ");
        
        std::string problem_str(problem_start);
        ResolutionStatus status = henryEngine.resolveProblem(problem_str);
        
        std::cout << "[CHAOS ENGINE RESPONSE] Status: " << statusToString(status) << std::endl;
        printf("Pringles Remaining: %d | Power Left: %d | Shrimp: %d\n", 
               henryEngine.getPringles(), henryEngine.getPowerLeft(), henryEngine.getShrimpCount());

    } else if (cmd == "engine") {
        char *sub_cmd = strtok(NULL, " ");
        if (sub_cmd && strcmp(sub_cmd, "status") == 0) {
            display_sysinfo(); 
        } else {
            printf("[SD/OS CHAOS] Unknown engine command. Try 'engine status'\n");
        }
    } 
    // --- End C++ Engine Integration ---
    
    // --- C Shell Commands ---
    else if (cmd == "dir") dir();
    else if (cmd == "cd") cd(strtok(NULL, " "));
    else if (cmd == "copy") copy(strtok(NULL, " "), strtok(NULL, " "));
    else if (cmd == "del") del(strtok(NULL, " "));
    else if (cmd == "mkdir") mkdir_cmd(strtok(NULL, " "));
    else if (cmd == "rmdir") rmdir_cmd(strtok(NULL, " "));
    else if (cmd == "type") type(strtok(NULL, " "));
    else if (cmd == "ren") ren(strtok(NULL, " "), strtok(NULL, " "));
    else if (cmd == "uname") uname_cmd();
    else if (cmd == "tasks") tasks();
    else if (cmd == "cls") cls();
    else if (cmd == "shutdown") shutdown_cmd();
    else if (cmd == "restart") restart();
    else if (cmd == "help") help();
    else if (cmd == "honk") {
        if (goose_enabled) {
            honk();
        } else {
            printf("Unknown command: %s\n", cmd_token);
        }
    } else {
        printf("Unknown command: %s\n", cmd_token);
    }

    free(input_copy);
}

int main() {
    splash_screen();
    display_sysinfo();

    char input[MAX_INPUT];
    while (1) {
        printf("SD/OS> ");
        if (fgets(input, sizeof(input), stdin)) {
            input[strcspn(input, "\n")] = 0; // remove newline
            parseCommand(input);
        }
    }

    return 0;
}
