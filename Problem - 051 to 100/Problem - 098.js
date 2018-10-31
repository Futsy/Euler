let buildSquaresArray = (upperbound) => {
    let squares = [];
    for (let i = 1; (i * i) <= upperbound; i++) {
        squares.push(i * i);
    }
    return squares;
}

let getLongestAnagram = (sortedToAnagramMap) => {
    return Math.max(...(Array.from(sortedToAnagramMap.keys()).map(el => el.length)));
}

let getAnagramMap = () => {
    let sortedToAnagramMap = new Map();

    for (const element of input) {
        let elementSorted = element.split('').sort().join('');
        let foundElement = sortedToAnagramMap.get(elementSorted);

        if (foundElement == undefined) {
            foundElement = [];
        }
        
        foundElement.push(element);
        sortedToAnagramMap.set(elementSorted, foundElement);
    }

    // We only care about entries that hold more then 2 values
    let anagrams = new Map();
    for (const [key, value] of sortedToAnagramMap) {
        if (value.length >= 2)
            anagrams.set(key, value);
    }

    return anagrams;
}

let getValidSquaresForWord = (word, viableSquares) => {
    let viableSquaresForWord = [];
    
    for (const viableSquare of viableSquares) {
        let mapping = new Map();
        let valid = true;
        let existing = [];

        for (let i = 0; i < word.length; i++) {
            if (existing.indexOf(viableSquare[i]) != -1) {
                valid = false;
                break;
            }

            if (mapping.get(word[i]) == undefined) {
                mapping.set(word[i], viableSquare[i]);
                existing.push(viableSquare[i]);
            }
        }
        if (valid) {
            viableSquaresForWord.push(viableSquare);
        }
    }
    return viableSquaresForWord;
}

let getValidSquaresForCombinations = (value, viableSquaresForWords) => {
    if (!viableSquaresForWords.every((l) => l.length > 0)) {
        return [];
    }

    // Create all the mappings based on the first word
    let maps = [];
    for (const squareFirstWord of viableSquaresForWords[0]) {
        let map = new Map();
        for (let i = 0; i < value[0].length; i++) {
            if (map.get(value[0][i]) == undefined) {
                map.set(value[0][i], squareFirstWord[i]);
            }
        }
        maps.push(map);
    }

    // Validate the mapping works for the other anagrams
    let validSquares = [];
    for (let i = 0; i < maps.length; i++) {
        let validWords = true;
        let validSubSquares = [];

        for (const word of value.slice(1, value.length)) {
            let toNumber = "";

            for (let j = 0; j < word.length; j++) {
                toNumber += maps[i].get(word[j]);
            }

            // If it is not a square we don't care about this mapping
            if (viableSquaresForWords[0].indexOf(toNumber) == -1) {
                validWords = false;
                break;
            }
            else {
                validSubSquares.push(toNumber);
            }
        }
        if (validWords) {
            validSquares = validSquares.concat(validSubSquares);
        }
    }

    return validSquares;
}

let getLargestAnagramicSquare = () => {
    let result = "0";
    let anagramMap = getAnagramMap();
    let squares = buildSquaresArray(Math.pow(10, getLongestAnagram(anagramMap))).map((elem) => elem.toString());
    
    for (const [key, value] of anagramMap) {
        let validSolutions = getValidSquaresForCombinations(value, 
            value.map((word) => getValidSquaresForWord(word, 
            squares.filter((elem) => elem.length == key.length).reverse())));

        if (validSolutions.length > 0 && parseInt(validSolutions[0], 10) > parseInt(result, 10)) {
            result = validSolutions[0];
        }
    }
    return result;
}
