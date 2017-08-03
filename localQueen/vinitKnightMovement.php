<?php
/**
 * @author vinit payal
 */

/**
 * Coordinates Sequence
 *
 *     | 0 1 2 3 4 5 6 7
 *   --|------------------
 *   0 |
 *   1 |
 *   2 |
 *   3 |
 *   4 |
 *   5 |
 *   6 |
 *   7 |
 *
 * Instructions To Run :-
 *
 *       --> If PHP is installed just download this file and on command line execute php and name of file.
 *          For Example :- php nameOfFile.php(php vinitKnightMovement.php )
 *      --> Otherwise for online compiling use https://repl.it/JwF8/0 or http://ideone.com/CVzReS link.
 *
 * Instructions to test with various Inputs :-
 *
 *      ---> To changing first player's initial point find for $player1->setCurrPosition(2,1);
 *          and change the numeric numbers with your inputs same thing can be done for player2 also.
 *      --> You can also change the name of players by changing $player1->setName("Vinit");
 *
 * Assumptions :-
 *          --> First move will be made by first player
 *          --> Chess Board is of size 8 x 8
 */


class Chess{
	/*
	Here 1 denote to black cell and 0 denote to white cell
	and -1 denotes obstacle
	*/
	private $chessBoard = array(array());

	function getCellValue($outerIndex, $innerIndex){
		if(($outerIndex%2 == 0 && $innerIndex % 2 != 0) || ($outerIndex%2 != 0 && $innerIndex % 2 == 0)){
			return 1;
		}
		else if(($outerIndex%2 == 0 && $innerIndex % 2 == 0) || ($outerIndex%2 != 0 && $innerIndex % 2 != 0)){
			return 0;
		}
	}

	function __construct(){

		//Intialize chess board elements
		for($outerIndex = 0; $outerIndex <= 7; $outerIndex++){
		  	$currRow = array();
			for($innerIndex = 0; $innerIndex <= 7; $innerIndex++){
				$currRow[$innerIndex] = $this->getCellValue($outerIndex, $innerIndex);
			}
	
			$this->chessBoard[$outerIndex] = $currRow;
		}
	}

	function printChessBoard(){
		for($outerIndex = 0; $outerIndex <= 7; $outerIndex++){
			for($innerIndex = 0; $innerIndex <= 7; $innerIndex++){
			  
				echo $this->chessBoard[$outerIndex][$innerIndex]." ";
				
			}

			echo "\n";
		}
	}

	function markCellAsObstacle($x, $y){
		$this->chessBoard[$x][$y] = -1;
	}

	function removeObstacle($x, $y){
		$this->chessBoard[$x][$y] = $this->getCellValue($x, $y);
	}

	function nextMove(){
		return [
			['x' => 2, 'y' => 1],
			['x' => 2, 'y' => -1],
			['x' => -2, 'y' =>1],
			['x' => -2, 'y' => -1],
			['x' => 1, 'y' => 2],
			['x' => 1, 'y' => -2],
			['x' => -1, 'y' =>2],
			['x' => -1, 'y' => -2]
			
		];
	}
	function isValidMove($x, $y){
		 return ($x >= 0 && $x <= 7 && $y >= 0 && $y <= 7 && $this->chessBoard[$x][$y] != -1);
	}

	function applyNextPossibleMoves($x, $y){

		$validMoveResults = array();
		$allPossibleMoves = $this->nextMove();

		foreach ($allPossibleMoves as $moveArray) {
			$newX = $x + $moveArray['x'];
			$newY = $y  + $moveArray['y'];

			if($this->isValidMove($newX, $newY)){
				array_push($validMoveResults, ['x' => $newX, 'y' => $newY]);
			}
		}

		return $validMoveResults;
	}
}

class Player{
	private $name;
	private $currPos = ["x" => 0, "y" => 0];

	function getName(){
		return $this->name;
	}

	function setName($name){
		$this->name = $name;
	}

	function setCurrPosition($row, $column){
		$this->currPos["x"] = $row;
		$this->currPos["y"] = $column;
	}

	function getCurrPosition(){
		return $this->currPos;
	}
}

class QueueElement{
  public $value;
  public $next;
}

//Customized Queue class for customized BFS
class Queue{
  private $front = null;
  private $back = null;

  public function isEmpty(){
    return $this->front == null;
  }

  public function enqueue($value){
     $oldBack = $this->back;
     $this->back = new QueueElement(); 
     $this->back->value = $value;
     if($this->isEmpty()){
       $this->front = $this->back; 
     }else{
       $oldBack->next = $this->back;
     }
  }

  public function getFront(){
      if($this->isEmpty()){
          return null;
      }
      $frontValue = $this->front->value;
      return $frontValue;
  }

  public function dequeue(){
    if($this->isEmpty()){
      return null; 
    }
    $removedValue = $this->front->value;
    $this->front = $this->front->next;
    return $removedValue;
  }
}

class Position{
	private $xCoordinate = 0;
	private $yCoordinate = 0;
	public  $path = "";

	public function __construct($x, $y) {
	    $this->xCoordinate = $x;
	    $this->yCoordinate = $y;
	}

	public function getPosition(){
		return [
		'x' => $this->xCoordinate,
		'y' => $this->yCoordinate,
		];
	}
}

class Distance{
    private $firstHorseDistance;
    private $secondHorseDistance;

    function __construct($firstHorseDistance, $secondHorseDistance){
        $this->firstHorseDistance = $firstHorseDistance;
        $this->secondHorseDistance = $secondHorseDistance;
    }

    public function getDistances(){
        return [1 => $this->firstHorseDistance,2 => $this->secondHorseDistance];
    }

    public function setFirstHorseDistance($dist){
        $this->firstHorseDistance = $dist;
    }

    public function setSecondHorseDistance($dist){
        $this->secondHorseDistance = $dist;
    }

}

/**
    Chess board creation and players creation
**/
$chessObj = new Chess();

$player1 = new Player();
$player1->setName("Vinit");
$player1->setCurrPosition(0,0);

$player2 = new Player();
$player2->setName("Nilesh");
$player2->setCurrPosition(2,1);

$p1Curr = $player1->getCurrPosition();
$p2Curr = $player2->getCurrPosition();

$someOneIsAlreadyOnFinalDestination = false;
if($p1Curr['x'] == 7 && $p1Curr['y'] == 7){
    $someOneIsAlreadyOnFinalDestination = true;
    echo $player1->getName()." won as he is already on destination\n";
}
elseif ($p2Curr['x'] == 7 && $p2Curr['y'] == 7){
    $someOneIsAlreadyOnFinalDestination = true;
    echo $player2->getName()." won as he is already on destination\n";
}

$queueForP1 = new Queue();
$queueForP2 = new Queue();

$cellDistances = array(array());

for($outerIndex = 0; $outerIndex < 8; $outerIndex++) {
    for ($innerIndex = 0; $innerIndex < 8; $innerIndex++) {
        $cellDistances[$outerIndex][$innerIndex] = new Distance(0,0);
    }
}

$initialPositionP1 = new Position($p1Curr['x'],$p1Curr['y']);
$initialPositionP2 = new Position($p2Curr['x'],$p2Curr['y']);

$initialPositionP1->path = "(".$p1Curr['x'].",".$p1Curr['y'].")";
$initialPositionP2->path = "(".$p2Curr['x'].",".$p2Curr['y'].")";

$queueForP1->enqueue($initialPositionP1);
$queueForP2->enqueue($initialPositionP2);

//Will denote which horse will make first move
$currTurn = 1;

$horse1CurrentMove = 0;
$horse2CurrentMove = 0;

while(!$someOneIsAlreadyOnFinalDestination){
    if($currTurn == 1) {
        while (true) {

            $posObj = $queueForP1->getFront();
            $currCoordinates = $posObj->getPosition();

            $currHorse1Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[1];
            $currHorse2Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[2];

            //At a step process only similar step reaching nodes
            if($currHorse1Steps != $horse1CurrentMove){
                $horse1CurrentMove++;
                $currTurn = 2;
                break;
            }

            $queueForP1->dequeue();

            $nextPossibleMoves = $chessObj->applyNextPossibleMoves($currCoordinates['x'], $currCoordinates['y']);

            foreach ($nextPossibleMoves as $moveCoordinate) {

                $newXCoordinate = $moveCoordinate['x'];
                $newYCoordinate = $moveCoordinate['y'];

                if ($newXCoordinate == 7 && $newYCoordinate == 7) {
                    echo "\n----------------------------------------------------------------\n";
                    echo $player1->getName()." Won and number of steps required are " . ($currHorse1Steps + 1) . "\n";
                    echo "----------------------------------------------------------------\n";
                    echo " Path Followed is ".$posObj->path."-->(".$newXCoordinate.",".$newYCoordinate.")\n";
                    
                    return;
                }

                $newPos = new Position($newXCoordinate, $newYCoordinate);

                $newPos->path = $posObj->path . " -->(" . $moveCoordinate['x'] . "," . $moveCoordinate['y'] . ")";

                $newHorse1Steps = $currHorse1Steps + 1;

                if ($newHorse1Steps != $currHorse2Steps) {
                    $cellDistances[$newXCoordinate][$newYCoordinate]->setFirstHorseDistance($newHorse1Steps);
                    $queueForP1->enqueue($newPos);
                }

            }
        }
    }
    elseif ($currTurn == 2){
        while (true) {
            $posObj = $queueForP2->getFront();
            $currCoordinates = $posObj->getPosition();

            $currHorse1Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[1];
            $currHorse2Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[2];

            if ($currHorse2Steps != $horse2CurrentMove) {
                $horse2CurrentMove++;
                $currTurn = 1;
                break;
            }

            $queueForP2->dequeue();

            $currCoordinates = $posObj->getPosition();

            $currHorse1Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[1];
            $currHorse2Steps = $cellDistances[$currCoordinates['x']][$currCoordinates['y']]->getDistances()[2];

            $nextPossibleMoves = $chessObj->applyNextPossibleMoves($currCoordinates['x'], $currCoordinates['y']);

            foreach ($nextPossibleMoves as $moveCoordinate) {

                $newXCoordinate = $moveCoordinate['x'];
                $newYCoordinate = $moveCoordinate['y'];

                if ($newXCoordinate == 7 && $newYCoordinate == 7) {

                    echo "----------------------------------------------------------------\n";
                    echo $player1->getName()." Won and number of steps required are " . ($currHorse2Steps + 1) . "\n";
                    echo "----------------------------------------------------------------\n";
                    echo "Path Followed is ".$posObj->path."-->(".$newXCoordinate.",".$newYCoordinate.")\n";
                    echo "----------------------------------------------------------------\n\n";
                    return;
                }

                $newPos = new Position($newXCoordinate, $newYCoordinate);

                $newPos->path = $posObj->path . " -->(" . $moveCoordinate['x'] . "," . $moveCoordinate['y'] . ")";

                $newHorse2Steps = $currHorse2Steps + 1;

                //As we are assuming always first horse will move first
                if ($newHorse1Steps + 1 != $currHorse2Steps) {
                    $cellDistances[$newXCoordinate][$newYCoordinate]->setSecondHorseDistance($newHorse2Steps);
                    $queueForP2->enqueue($newPos);
                }
            }
            $currTurn = 1;
        }
    }

}




?>