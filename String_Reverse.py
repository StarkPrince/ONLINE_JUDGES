Create GUI for the ff. Code

Dim number, digits As Integer Dim myString As String
number =53
If number <10 Then digits =1
Elself number <100 Then digits =2
Else digits =3
End If

Create GUI for the ff.Code
Dim numberOrdered As Integer
Dim ItemPrice As Integer Integer.TryPars (txtOrder. Text, numberOrdered)
Select Case numberOrdered
Case 1 To 5 itemPrice =25
Case 1 To 10 itemPrice =23
Case Is >10 itemPrice =20
Case Else itemPrice =0
End Select
txtResult. Text= itemPrice. ToString("C2")