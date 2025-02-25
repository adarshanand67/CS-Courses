'''
Group No. 7
Team Member 1:  Name: Aniket Akshay Chaudhri
                Roll No. 2003104
Team Member 2:  Name: Adarsh Anand
                Roll No. 2003101

Date of Submission: 30 September 2022
'''

# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
#
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random
import util
import math

from game import Agent


class ReflexAgent(Agent):
    """
      A reflex agent chooses an action at each choice point by examining
      its alternatives via a state evaluation function.

      The code below is provided as a guide.  You are welcome to change
      it in any way you see fit, so long as you don't touch our method
      headers.
    """

    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {North, South, West, East, Stop}
        """
        # Collect legal moves and successor states
        # ['North', 'South', 'West', 'East', 'Stop']
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(
            gameState, action) for action in legalMoves]

        bestScore = max(scores)
        bestIndices = [index for index in range(
            len(scores)) if scores[index] == bestScore]

        # Pick randomly among the best
        chosenIndex = random.choice(bestIndices)

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        # * Q1
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        curFood = currentGameState.getFood()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        # print(newGhostStates[0])
        # print(type(newGhostStates))
        newScaredTimes = [ ghostState.scaredTimer for ghostState in newGhostStates]
        # print(newScaredTimes)
        new_food_list = newFood.asList()
        # [(7, 5), (7, 5)]
        ghosts_positions = successorGameState.getGhostPositions()
        # print(ghosts_positions)

        min_distance_to_ghost = float("inf")  # min distance to ghost
        for ghost in ghosts_positions:
            min_distance_to_ghost = min(manhattanDistance(
                ghost, newPos), min_distance_to_ghost)

        min_distance_to_food = float("inf")  # min distance to food
        for food in new_food_list:
            min_distance_to_food = min(manhattanDistance(
                food, newPos), min_distance_to_food)

        count = len(new_food_list)  # Number of food left

        if len(new_food_list) < len(food_list):  # If we eat food
            count = 10000  # count becomes very large
        if count == 0:  # If we eat all food
            count = -1000

        if min_distance_to_ghost < 2:  # If we are close to ghost
            min_distance_to_ghost = -100000
        else:
            min_distance_to_ghost = 0

        # print(newScaredTimes[0])
        if newScaredTimes[0] > 0:
            min_distance_to_ghost = 0
        # print(successorGameState.getScore())
        return (min_distance_to_ghost + 1.0 / min_distance_to_food + count) - successorGameState.getScore()

        "*** YOUR CODE HERE ***"
        # print(newPos)
        # print(newFood)
        # print(newGhostStates)
        # print(newScaredTimes)

        # initialise the score
        finalScore = 0
        finalScore += successorGameState.getScore()

        # if win state return the max score
        if successorGameState.isWin():
            return float("inf")

        # if lose state return the min score
        if successorGameState.isLose():
            return float("-inf")

        # get minimum ghost distance
        min_ghost_distance = 100000
        for ghost in newGhostStates:
            ghost_distance = manhattanDistance(newPos, ghost.getPosition())
            min_ghost_distance = min(min_ghost_distance, ghost_distance)

        # if ghost is too close, decrease the score
        if min_ghost_distance < 2:
            finalScore -= 1000

        # get minimum food distance
        min_food_distance = 100000
        for food in newFood.asList():
            food_distance = manhattanDistance(newPos, food)
            min_food_distance = min(min_food_distance, food_distance)

        # maintain the score asscociated with food
        count = -50

        # if pacman eats food in successor state, increase the score
        if (len(curFood.asList()) - len(newFood.asList())) > 0:
            count = 1000

        return finalScore + count - min_food_distance



def scoreEvaluationFunction(currentGameState):
    """
      This default evaluation function just returns the score of the state.
      The score is the same one displayed in the Pacman GUI.

      This evaluation function is meant for use with adversarial search agents
      (not reflex agents).
    """
    return currentGameState.getScore()


class MultiAgentSearchAgent(Agent):
    """
      This class provides some common elements to all of your
      multi-agent searchers.  Any methods defined here will be available
      to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

      You *do not* need to make any changes here, but you can if you want to
      add functionality to all your adversarial search agents.  Please do not
      remove anything, however.

      Note: this is an abstract class: one that should not be instantiated.  It's
      only partially specified, and designed to be extended.  Agent (game.py)
      is another abstract class.
    """

    def __init__(self, evalFn='scoreEvaluationFunction', depth='2'):
        self.index = 0  # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)


class MinimaxAgent(MultiAgentSearchAgent):
    """
      Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action from the current gameState using self.depth
          and self.evaluationFunction.

          Here are some method calls that might be useful when implementing minimax.

          gameState.getLegalActions(agentIndex):
            Returns a list of legal actions for an agent
            agentIndex=0 means Pacman, ghosts are >= 1

          gameState.generateSuccessor(agentIndex, action):
            Returns the successor game state after an agent takes an action

          gameState.getNumAgents():
            Returns the total number of agents in the game
        """
        "*** YOUR CODE HERE ***"

        def minimax(state, depth, agent):

            # If we found the bottom nodes or we don't have any moves or we won or lost: Call evaluation function and return the result
            if depth == self.depth or state.getLegalActions(agent) == 0 or state.isWin() or state.isLose():
                return (self.evaluationFunction(state), None)

            minfinity = float("-inf")
            val = minfinity
            # If agent is pacman
            if (agent is 0):
                for a in state.getLegalActions(agent):
                    (v1, a1) = minimax(state.generateSuccessor(agent, a),
                                       depth, (agent + 1) % state.getNumAgents())
                    #* Find the maximum value
                    if (v1 > val):
                        val = v1
                        maxa = a
            # Return the value and the action from which we found max
            if val is not minfinity:
                return (val, maxa)

            infinity = float("inf")
            val = infinity
            # If agent is ghost
            if (agent is not 0):
                for a in state.getLegalActions(agent):
                    # If it isn't the last ghost keep the same depth
                    if (((agent + 1) % state.getNumAgents()) is not 0):
                        (v1, a1) = minimax(state.generateSuccessor(agent, a),
                                           depth, (agent + 1) % state.getNumAgents())
                    # else if it is next_depth = depth + 1
                    else:
                        (v1, a1) = minimax(state.generateSuccessor(agent, a),
                                           depth + 1, (agent + 1) % state.getNumAgents())
                    # * Find the minimum value
                    if (v1 < val):
                        val = v1
                        mina = a
            # Return the value and the action from which we found min
            if val is not infinity:
                return (val, mina)

      ############################################################
        return minimax(gameState, 0, 0)[1]
        # util.raiseNotDefined()


        util.raiseNotDefined()

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
      Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
          Returns the minimax action using self.depth and self.evaluationFunction
        """
        "*** YOUR CODE HERE ***"
        # print(gameState.getNumAgents())

        # max-value function
        def max_value(gameState, depth, alpha, beta):
            # if game is over or depth is reached, return the score
            if gameState.isWin() or gameState.isLose() or depth == 0:
                return self.evaluationFunction(gameState)
            v = -100000 # initialise the value
            for action in gameState.getLegalActions(0):
                # find the max value of all the successors
                v = max(v, min_value(gameState.generateSuccessor(0, action), depth, 1, alpha, beta))
                if v > beta: # prune
                    return v
                alpha = max(alpha, v) # update alpha
            return v

        # min-value function
        def min_value(gameState, depth, agent, alpha, beta):
            # if game is over or depth is reached, return the score
            if gameState.isWin() or gameState.isLose() or depth == 0:
                return self.evaluationFunction(gameState)
            v = 100000 # initialise the value
            for action in gameState.getLegalActions(agent): # for each action in legal actions
                if agent == gameState.getNumAgents() - 1: # if last ghost
                    v = min(v, max_value(gameState.generateSuccessor(agent, action), depth - 1, alpha, beta)) # call max_value on next depth
                else: # if not last ghost
                    v = min(v, min_value(gameState.generateSuccessor(agent, action), depth, agent + 1, alpha, beta)) # call min_value with next ghost
                if v < alpha: # prune
                    return v
                beta = min(beta, v) # update beta
            return v

        # initialise the best action
        v = -100000
        best_action = None
        alpha = -100000 # initialise alpha
        beta = 100000 # initialise beta
        for action in gameState.getLegalActions(0):
            # find the max value of all the successors
            curr = min_value(gameState.generateSuccessor(0, action), self.depth, 1, alpha, beta)
            if curr > v:
                v = curr
                best_action = action
            if v > beta: # prune
                return best_action
            alpha = max(alpha, v) # update alpha
        return best_action


        util.raiseNotDefined()


class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
          Returns the expectimax action using self.depth and self.evaluationFunction

          All ghosts should be modeled as choosing uniformly at random from their
          legal moves.
        """
        "*** YOUR CODE HERE ***"

        # Approach: same as minimax, but instead of taking the min value, take the average value

        # max-value function
        def max_value(gameState, depth):
            # if game is over or depth is reached, return the score
            if gameState.isWin() or gameState.isLose() or depth == 0:
                return self.evaluationFunction(gameState)
            v = -100000 # initialise the value
            for action in gameState.getLegalActions(0):
                # find the max value of all the successors
                v = max(v, exp_value(gameState.generateSuccessor(0, action), depth, 1))
            return v

        # expetation-value function
        def exp_value(gameState, depth, agent):
            # if game is over or depth is reached, return the score
            if gameState.isWin() or gameState.isLose() or depth == 0:
                return self.evaluationFunction(gameState)
            v = 0 # initialise the value
            for action in gameState.getLegalActions(agent):
                # if the agent is the last ghost, call max_value for pacman with depth - 1
                if agent == gameState.getNumAgents() - 1:
                    v += max_value(gameState.generateSuccessor(agent, action), depth - 1)
                # else call exp_value for the next ghost
                else:
                    v += exp_value(gameState.generateSuccessor(agent, action), depth, agent + 1)
            # return the average value
            return v / len(gameState.getLegalActions(agent))

        # initialise the best action
        v = -100000
        best_action = None
        for action in gameState.getLegalActions(0):
            # find the max value of all the successors
            curr = exp_value(gameState.generateSuccessor(0, action), self.depth, 1)
            if curr > v:
                v = curr
                best_action = action
        return best_action


        util.raiseNotDefined()


def betterEvaluationFunction(currentGameState):
    """
      Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
      evaluation function (question 5).

    DESCRIPTION: States are evaluated based on the following factors:
    - the number of food pellets left
    - the distance to the closest food pellet
    - the distance to the closest ghost
    - the distance to the closest scared ghost
    - the number of capsules left
    - the number of ghosts and scared ghosts
    - the score

    """
    "*** YOUR CODE HERE ***"
    newPos = currentGameState.getPacmanPosition() # newPos = (x,y)
    newFood = currentGameState.getFood() # newFood = grid
    newGhostStates = currentGameState.getGhostStates() # newGhostStates = list of ghost states
    #newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

    # Get the current score of the successor state
    score = currentGameState.getScore()

    ghostValue = 10.0
    foodValue = 10.0
    # bigger value for the scared ghost because we want to prefer it as a move
    scaredGhostValue = 50.0

    # For every ghost
    for x in newGhostStates:
        # Find the distance from pacman
        dis = manhattanDistance(newPos, x.getPosition())
        if dis > 0:
            """
            If the ghost is edible, and the ghost is near, the distance
            is small.
            """
            if x.scaredTimer > 0:
                score += scaredGhostValue / dis
            else:
                score -= ghostValue / dis
            """
            If the ghost is not edible, and the ghost is far, the distance
            is big.
            """

    # Find the distance of every food and insert it in a list using manhattan
    foodList = newFood.asList()
    foodDistances = []
    """
    If the food is very close to the pacman then the distance is small and
    we want such a situation to proceed.
    """
    for x in foodList:
        foodDistances.append(manhattanDistance(newPos, x))


    return finalScore
    # return score + 1 / closest_food_dist - 1 / closest_ghost_dist + 1 / closest_scared_ghost_dist - 1 / num_food_left - 1 / num_capsules_left + 1 / num_scared_ghosts - 1 / num_ghosts

    util.raiseNotDefined()


# Abbreviation
better = betterEvaluationFunction
