# Pseudocode - Train Game (Hammad)

FUNCTION AddCompartment(train, id, position)
    node ← new compartment(id, position)
    IF train.first IS NULL
        train.first ← node
        train.last ← node
    ELSE
        train.last.next ← node
        train.last ← node
    END IF
END FUNCTION

FUNCTION MoveTrain(train, steps)
    temp ← train.first
    WHILE temp IS NOT NULL
        temp.position ← temp.position + steps
        temp ← temp.next
    END WHILE
END FUNCTION

FUNCTION DisplayTrain(train)
    temp ← train.first
    WHILE temp IS NOT NULL
        PRINT temp.comp_id, temp.position
        temp ← temp.next
    END WHILE
END FUNCTION

FUNCTION CheckCollision(train1, train2)
    t1 ← train1.first
    WHILE t1 IS NOT NULL
        t2 ← train2.first
        WHILE t2 IS NOT NULL
            IF t1.position = t2.position
                RETURN "Collision"
            END IF
            t2 ← t2.next
        END WHILE
        t1 ← t1.next
    END WHILE
    RETURN "Safe"
END FUNCTION