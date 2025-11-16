"Utility methods to work around GNU Smalltalk float printing bug"

Object subclass: NumberFormatter [
    <comment: 'Utility class to format numbers safely'>
    
    NumberFormatter class >> format: aNumber [
        "Format a number to 2 decimal places, avoiding GNU Smalltalk bug"
        | intPart fracPart rounded |
        
        "Round to 2 decimal places"
        rounded := (aNumber * 100) rounded / 100.
        
        "Get integer and fractional parts"
        intPart := rounded truncated.
        fracPart := ((rounded - intPart) * 100) rounded abs.
        
        "Format as string"
        ^ intPart printString, '.', 
          (fracPart < 10 
              ifTrue: ['0', fracPart printString] 
              ifFalse: [fracPart printString])
    ]
]

