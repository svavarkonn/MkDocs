# Code tests
=== "Python"
    ```python
    # Finally, I can present Python code on my website.

    def sum(a, b):
        return a + b

    def sub(a, b):
        return a - b

    def mul(a, b):
        return a * b

    def div(a, b):
        return a / b

    a = float(input('First: '))
    b = float(input('Second: '))
    op = input('Operation (sum/sub/mul/div): ')

    if op == 'sum':
        print(f'a + b = {sum(a, b)}')
    elif op == 'sub':
        print(f'a - b = {sub(a, b)}')
    elif op == 'mul':
        print(f'a * b = {mul(a, b)}')
    elif op == 'div':
        print(f'a / b = {div(a, b)}')
    else:
        print('Invalid Operation!')
    ```
=== "C++"
    ```cpp
    /* How about C++? */

    private void index(){
    MessageBox.Show("hello world");
    }
    ```
=== "HTML and CSS"
    ```HTML
    // Or HTML and CSS (with a few extra long lines of code)?

    <!doctype html>
    <html lang="en">
    <head>
        <meta charset="utf-8">
        <title>Battleship</title>
        <style>
        body {
            background-color: black;
        }
        div#board {
            position: relative;
            width: 1024px;
            height: 863px;
            margin: auto;
            background: url("board.jpg") no-repeat;
        }
        div#messageArea {
            position: absolute;
            top: 0px;
            left: 0px;
            color: rgb(83, 175, 19);
        }
        table {
            position: absolute;
            left: 173px;
            top: 98px;
            border-spacing: 0px;
        }
        td {
            width: 94px;
            height: 94px;
        }
        form {
            position: absolute;
            bottom: 0px;
            right: 0px;
            padding: 15px;
            background-color: rgb(83, 175, 19);
        }
        form input {
            background-color: rgb(152, 207, 113);
            border-color: rgb(83, 175, 19);
            font-size: 1em;
        } 
        .hit {
            background: url("ship.png") no-repeat center center;
        }
        .miss {
            background: url("miss.png") no-repeat center center;
        }
        </style>
    </head>
    </body>
        <div id="board">
        <div id="messageArea"></div>
        <table>
            <tr>
            <td id="00"></td><td id="01"></td><td id="02"></td><td id="03"></td><td id="04"></td><td id="05"></td><td id="06"></td>
            </tr>
            <tr>
            <td id="10"></td><td id="11"></td><td id="12"></td><td id="13"></td><td id="14"></td><td id="15"></td><td id="16"></td>
            </tr>
            <tr>
            <td id="20"></td><td id="21"></td><td id="22"></td><td id="23"></td><td id="24"></td><td id="25"></td><td id="26"></td>
            </tr>
            <tr>
            <td id="30"></td><td id="31"></td><td id="32"></td><td id="33"></td><td id="34"></td><td id="35"></td><td id="36"></td>
            </tr>
            <tr>
            <td id="40"></td><td id="41"></td><td id="42"></td><td id="43"></td><td id="44"></td><td id="45"></td><td id="46"></td>
            </tr>
            <tr>
            <td id="50"></td><td id="51"></td><td id="52"></td><td id="53"></td><td id="54"></td><td id="55"></td><td id="56"></td>
            </tr>
            <tr>
            <td id="60"></td><td id="61"></td><td id="62"></td><td id="63"></td><td id="64"></td><td id="65"></td><td id="66"></td>
            </tr>
        </table>
        <form>
            <input type="text" id="guessInput" placeholder="A0">
        <input type="button" id="fireButton" value="Fire!">
        </form>
        </div>
        <script src="battleship2.js"></script>
    </body>
    </html>
    ```
=== "JavaScript"
    ```js
    // Or JavaScript?

    var view = {
    displayMessage: function(msg) {
        var messageArea = document.getElementById("messageArea");
        messageArea.innerHTML = msg;
    },
    displayHit: function(location) {
        var cell = document.getElementById(location);
        cell.setAttribute("class", "hit");
    },
    displayMiss: function(location) {
        var cell = document.getElementById(location);
        cell.setAttribute("class", "miss");
    }
    };

    var model = {
    boardSize: 7,
    numShips: 3,
    shipLength: 3,
    shipsSunk: 0,
    ships: [{ locations: [0, 0, 0], hits: ["", "", ""] },
            { locations: [0, 0, 0], hits: ["", "", ""] },
            { locations: [0, 0, 0], hits: ["", "", ""] }],
    fire: function(guess) {
        for (var i=0; i<this.numShips; i++) {
        var ship = this.ships[i];
        var index = ship.locations.indexOf(guess);
        if (index >= 0) {
            ship.hits[index] = "hit";
            view.displayHit(guess);
            view.displayMessage("HIT!");
            if (this.isSunk(ship)) {
            view.displayMessage("You sank my battleship!");
            this.shipsSunk++;
            }
            return true;
        }
        }
        view.displayMiss(guess);
        view.displayMessage("You missed.");
        return false;
    },
    isSunk: function(ship) {
        for (var i = 0; i < this.shipLength; i++) {
        if (ship.hits[i] != "hit") {
            return false;
            }
        }
        return true;
    },
    generateShipLocations: function() {
        var locations;
        for (var i = 0; i < this.numShips; i++) {
            do {
            locations = this.generateShip();
            } while (this.collision(locations));
            this.ships[i].locations = locations;
        }
    },
    generateShip: function() {
        var direction = Math.floor(Math.random() * 2);
        var row;
        var col;
        if (direction === 1) {
        row = Math.floor(Math.random() * this.boardSize);
        col = Math.floor(Math.random() * (this.boardSize - (this.shipLength + 1)));
        } else {
        row = Math.floor(Math.random() * (this.boardSize - (this.shipLength +1)));
        col = Math.floor(Math.random() * this.boardSize);
        }
        var newShipLocations = [];
        for (var i = 0; i < this.shipLength; i++) {
        if (direction === 1) {
            newShipLocations.push(row + "" + (col + i));
        } else {
            newShipLocations.push((row+i) + "" + col);
        }
        }
        return newShipLocations;
    },
    collision: function(locations) {
        for (var i = 0; i < this.numShips; i++) {
        var ship = this.ships[i];
        for (var j = 0; j < locations.length; j++) {
            if (ship.locations.indexOf(locations[j]) >= 0) {
            return true;
            }
        }
        }
        return false;
    }
    };

    var controller = {
    guesses: 0,
    processGuess: function(guess) {
        var location = parseGuess(guess);
        if (location) {
        this.guesses++;
        var hit = model.fire(location);
        if (hit && model.shipsSunk === model.numShips) {
            view.displayMessage("You sank all my battleships, in " + this.guesses + " guesses");
        }
        }
    }
    
    }

    function parseGuess(guess) {
    var alphabet = ["A", "B", "C", "D", "E", "F", "G"];
    if (guess == null || guess.length !== 2) {
        alert("Oops, please enter a letter and a number on the board.");
    } else {
        var firstChar = guess.charAt(0);
        var row = alphabet.indexOf(firstChar);
        var column = guess.charAt(1);
        if (isNaN(row) || isNaN(column)) {
        alert("Oops, that isn't on the board.");
        } else if (row < 0 || row >= model.boardSize || column < 0 || column >= model.boardSize) {
        alert("Oops, that's off the board!");
        } else {
        return row + column;
        }
        return null;
    }
    }

    function init() {
    var fireButton = document.getElementById("fireButton");
    fireButton.onclick = handleFireButton;
    var guessInput = document.getElementById("guessInput");
    guessInput.onkeypress = handleKeyPress;
    model.generateShipLocations();
    }

    window.onload = init;

    function handleFireButton() {
    var guessInput = document.getElementById("guessInput");
    var guess = guessInput.value;
    controller.processGuess(guess);
    guessInput.value = "";
    }

    function handleKeyPress(e) {
    var fireButton = document.getElementById("fireButton");
    if (e.keyCode === 13) {
        fireButton.click();
        return false;
    }
    }



    /* model.fire("53");

    model.fire("06");
    model.fire("16");
    model.fire("26");

    model.fire("34");
    model.fire("24");
    model.fire("44");

    model.fire("12");
    model.fire("11");
    model.fire("10"); */

    /* console.log(parseGuess("A0"));
    console.log(parseGuess("B6"));
    console.log(parseGuess("G3"));
    console.log(parseGuess("H0"));
    console.log(parseGuess("A7")); */

    /* controller.processGuess("A0");

    controller.processGuess("A6");
    controller.processGuess("B6");
    controller.processGuess("C6");

    controller.processGuess("C4");
    controller.processGuess("D4");
    controller.processGuess("E4");

    controller.processGuess("B0");
    controller.processGuess("B1");
    controller.processGuess("B2"); */

    //view.displayMiss("00");
    //view.displayHit("34");
    //view.displayMiss("55");
    //view.displayHit("12");
    //view.displayMiss("25");
    //view.displayHit("26");
    //view.displayMessage("Tap tap, is this thing on?");
    ```

