<?php
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
		for($outerIndex = 0; $outerIndex < 7; $outerIndex++){
		  	$currRow = array();
			for($innerIndex = 0; $innerIndex < 7; $innerIndex++){
				$currRow[$innerIndex] = $this->getCellValue($outerIndex, $innerIndex);
			}
	
			$this->chessBoard[$outerIndex] = $currRow;
		}
	}

	function printChessBoard(){
		for($outerIndex = 0; $outerIndex < 7; $outerIndex++){
			for($innerIndex = 0; $innerIndex < 7; $innerIndex++){
			  
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
			['x' => -2, 'y' => -1]
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


$chessObj = new Chess();

$player1 = new Player();
$player1->setName("p1");
$player1->setCurrPosition(0,0);


$hi = fopen('php://stdin', "r");
$ho = fopen('php://stdout', "w");

while (true) {
	fscanf($hi, "%d", $n);
	if ($n == 42) break;
	fwrite($ho, sprintf("%d\n", $n));
}
 
fclose($ho);
fclose($hi);






?>