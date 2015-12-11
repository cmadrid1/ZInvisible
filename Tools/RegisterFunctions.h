#ifndef REGISTERFUNCTION_H
#define REGISTERFUNCTION_H

#include <set>
#include <string>
#include <vector>
#include <functional>

class NTupleReader;
class BaselineVessel;

namespace plotterFunctions
{
    class GenerateWeight;
    class LepInfo;
    class Fakebtagvectors;
    class GetSearchBin;
    class TriggerInfo;
    class PrepareMiniTupleVars;
    class NJetWeight;
}

class RegisterFunctions
{
private:

public:
    RegisterFunctions() {}
        
    virtual void registerFunctions(NTupleReader& tr) {};
    virtual void activateBranches(std::set<std::string>& activeBranches) {};
    virtual const std::set<std::string> getMiniTupleSet();
};

class RegisterFunctionsNTuple : public RegisterFunctions
{
private:
    BaselineVessel *myBLV;
    BaselineVessel *blvZinv;
    BaselineVessel *blvZinv1b;
    BaselineVessel *blvZinv2b;
    BaselineVessel *blvZinv3b;
    plotterFunctions::GenerateWeight *weights;
    plotterFunctions::NJetWeight *njWeight;
    plotterFunctions::LepInfo *lepInfo;
    plotterFunctions::Fakebtagvectors *fakebtagvectors;
    plotterFunctions::GetSearchBin *getSearchBin;
    plotterFunctions::TriggerInfo *triggerInfo;
    plotterFunctions::PrepareMiniTupleVars *prepareMiniTupleVars;

public:
    RegisterFunctionsNTuple();
    ~RegisterFunctionsNTuple();
    void registerFunctions(NTupleReader& tr);
    void activateBranches(std::set<std::string>& activeBranches);
};

class RegisterFunctionsCalcEff : public RegisterFunctions
{
private:
    BaselineVessel *myBLV;
    plotterFunctions::LepInfo *lepInfo;

public:
    RegisterFunctionsCalcEff();
    ~RegisterFunctionsCalcEff();
    void registerFunctions(NTupleReader& tr);
    void activateBranches(std::set<std::string>& activeBranches);
};

class RegisterFunctionsSyst : public RegisterFunctions
{
private:
    std::vector<std::function<void(NTupleReader&)> > funcs_;
    plotterFunctions::PrepareMiniTupleVars *prepareMiniTupleVars;
    plotterFunctions::NJetWeight *njWeight;
public:
    RegisterFunctionsSyst();
    ~RegisterFunctionsSyst();
    void addFunction(std::function<void(NTupleReader&)> func);
    void registerFunctions(NTupleReader& tr);
};

#endif
