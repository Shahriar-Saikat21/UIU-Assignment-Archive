def initialize():
    arr = []
    arrSize = int(input("Enter the size of the array: "))
    for i in range(arrSize):
        arr.append(int(input("Enter the element: ")))
    return arr


def calculateCost(currentState):
    cost = 0
    for i in range(len(currentState)):
        for j in range(i + 1, len(currentState)):
            if currentState[i] > currentState[j]:
                cost += 1
    return cost


def generateNeighbours(currentState):
    neighbors = []
    for i in range(len(currentState)-1):
        element = currentState[i]
        listOne = currentState[:i]
        listTwo = currentState[i+1:]
        for j in range(len(listTwo)):
            tempListOne = listTwo[:j+1]
            tempListTwo = listTwo[j+1:]
            newList = listOne+tempListOne+[element]+tempListTwo
            neighbors.append(newList)                   
    return neighbors


def stateGeneration(currentState):
    while(True):
        currentStateCost = calculateCost(currentState)
        print(currentState," " ,currentStateCost)
        minNextCost = 999999
        minNextState = []
        for neighbor in generateNeighbours(currentState):
            nextState = neighbor
            nextStateCost = calculateCost(nextState)
            if nextStateCost < minNextCost:
                minNextCost = nextStateCost
                minNextState = nextState
        if minNextCost < currentStateCost:
            currentState = minNextState
        else:
            print("Final State: ",currentState," ",currentStateCost)
            break


state = initialize()
stateGeneration(state)


