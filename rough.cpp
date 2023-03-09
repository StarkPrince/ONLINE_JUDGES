import numpy as npimport matplotlib.pyplot as plt import random #Load training data and testing data train = np.genfromtxt('DigitsTraining.csv', delimiter = ',') test = np.genfromtxt('DigitsTesting.csv', delimiter = ',') #Pre - processing data into data labels and data X_train = train[ :, 1 : ] y_train = train[ :, 0] X_test = test[ :, 1 : ] y_test = test[ :, 0] #To plot line y = ax + b def line(w, data = None) :a = - w[1] / w[2] b = - w[0] / w[2] x_line = np.linspace(0.4, 1, 100) if data is not None: return a * data + b else : return a * x_line + b def symmetry(X) :X_shapes =(16, 16) X = X.reshape(X_shapes) sV = np.mean(np.abs(X - np.flipup(X))) SH = symm =(sv + sh) / 2###################### # #YOUR CODE GOES HERE # ###################### # #please of the definition of simmetry found in the slides.You can use np.flipud and np.fliplr return symm Please provide the code -(#where it says - YOUR CODE GOES HERE) #Prepare Training Data for 7's and 1's. Please changed for the two digits you chose(one of them is the last digit of the driver license) #Extract the Digit1 and Digit2 from the data Digit1 = X_train[y_train == 7] y_train_Digit1 = np.ones(len(Digit1)) Digit2 = X_train[y_train == 1] y_train_Digit2 = - np.ones(len(Digit2)) symm_Digit2 =[symmetry(im) for im in Digit2] symm_Digit1 =[symmetry(im) for im in Digit1] #Calculate averages and symmetries of the digits in training data###################### # #YOUR CODE GOES HERE # ###################### # #Please use the definition of intensity.You can use the np.mean #Concatenate the intensities and symmetry new_Digit1 = np.c_[avg_intensity_Digit1, symm_Digit1] new_Digit2 = np.c_[avg_intensity_Digit2, symm_Digit2] #Stack all the data together and randomize their locations.X_new = np.r_[new_Digit1, new_Digit2] y_new = np.r_[y_train_Digit1, y_train_Digit2] R_num = np.random.randint(X_new.shape[0], size =(X_new.shape[0], )) X_new = X_new[R_num] y_new = y_new[R_num] Please provide the code -(#where it says - YOUR CODE GOES HERE) #Prepare the test data for 7's and 1's. Please adjust for your two numbers, where one of them is the last digit of your driver license X_test_Digit1 = X_test[y_test == 7] y_test_Digit1 = np.ones(len(X_test_Digit1)) X_test_Digit2 = X_test[y_test == 1] y_test_Digit2 = - np.ones(len(X_test_Digit2)) X_test_new = np.r_[X_test_Digit1, X_test_Digit2] y_test_new = np.r_[y_test_Digit1, y_test_Digit2] R = np.random.randint(X_test_new.shape[0], size =(X_test_new.shape[0], )) X_test_new = X_test_new[R] y_test_new = y_test_new[R] #Calculate averages and symmetries of the digits in testing data###################### # #YOUR CODE GOES HERE # ###################### # #please use the definition of on the slide.You can use np.mean test_symm =[symmetry(im) for im in X_test_new] X_test_final = np.c_[avg_int_test, test_symm] Please provide the code -(#where it says - YOUR CODE GOES HERE) #Prepare the test data for 7's and 1's. Please adjust for your two numbers, where one of them is the last digit of your driver license X_test_Digit1 = X_test[y_test == 7] y_test_Digit1 = np.ones(len(X_test_Digit1)) X_test_Digit2 = X_test[y_test == 1] y_test_Digit2 = - np.ones(len(X_test_Digit2)) X_test_new = np.r_[X_test_Digit1, X_test_Digit2] y_test_new = np.r_[y_test_Digit1, y_test_Digit2] R = np.random.randint(X_test_new.shape[0], size =(X_test_new.shape[0], )) X_test_new = X_test_new[R] y_test_new = y_test_new[R] #Calculate averages and symmetries of the digits in testing data###################### # #YOUR CODE GOES HERE # ###################### # #please use the definition of on the slide.You can use np.mean test_symm =[symmetry(im) for im in X_test_new] X_test_final = np.c_[avg_int_test, test_symm] Please provide the code -(#where it says - YOUR CODE GOES HERE) #Linear Regression def lin(input_data, y, input_data_test, y_test) :data = np.c_[np.ones((input_data.shape[0], 1)), input_data] #https: //docs.scipy.org/doc/numpy/reference/generated/numpy.c_.html data_test = np.c_[np.ones((input_data_test.shape[0],1)), input_data_test] ####################### # YOUR CODE GOES HERE # ####################### return Ein,Eout,W_lin Please provide the code - (# where it says -YOUR CODE GOES HERE ) def pocket(input_data,y,input_data_test,y_test,max_iter,w=None): data = np.c_[np.ones((input_data.shape[0],1)), input_data] #https://docs.scipy.org/doc/numpy/reference/generated/numpy.c_.html data_test = np.c_[np.ones((input_data_test.shape[0],1)), input_data_test] if w is None: w = np.random.random(data.shape[1]).reshape(-1,1) else: w = w.reshape(-1,1) wf=w current = np.sign(data @ w) f = y.reshape(-1,1) y_test =y_test.reshape(-1,1) difference = (f != current) Ein=[] Eout=[] error=difference.sum() Ein.append(error * (1/len(difference))) current_test= np.sign(data_test @ wf) difference_test= (y_test != current_test) error_test=difference_test.sum() Eout.append(error_test * (1/len(difference_test))) t = 0 ####################### # YOUR CODE GOES HERE # ####################### #Please implement the logic of the pocket algorithm. Remember that w must be updated according to the evolution of the error return Ein,Eout,wf Please provide the code - (# where it says -YOUR CODE GOES HERE ) #Using pocket algorithm Ein, Eout,w = pocket(X_new, y_new,X_test_final,y_test_new, 1000) print('Min Ein Pocket=',min(Ein)) print('Min Eout Pocket=',min(Eout)) #Ploting plt.scatter(avg_intensity_Digit2, symm_Digit2, marker = 'x', color = 'red') plt.scatter(avg_intensity_Digit1, symm_Digit1, marker='o', color = 'blue') plt.plot(x_line, line(w)) plt.show() #Plot Ein and Eout plt.title('Ein/Eout Pocket') plt.xlabel('Iterations') plt.ylabel('Error %') plt.plot(Ein, label='Ein') plt.plot(Eout, label = 'Eout') plt.legend() plt.show() Ein, Eout,w = lin(X_new, y_new,X_test_final,y_test_new) plt.scatter(avg_intensity_Digit2, symm_Digit2, marker = 'x', color = 'red') plt.scatter(avg_intensity_Digit1, symm_Digit1, marker='o', color = 'blue') plt.plot(x_line, line(w)) plt.show() print('Min Ein Lin=',Ein) print('Min Eout Lin=',Eout) Ein, Eout,w = pocket(X_new, y_new,X_test_final,y_test_new, 1000,w) print('Min Ein Pocket with Lin=',min(Ein)) print('Min Eout Pocket with Lin=',min(Eout)) plt.scatter(avg_intensity_Digit2, symm_Digit2, marker = 'x', color = 'red') plt.scatter(avg_intensity_Digit1, symm_Digit1, marker='o', color = 'blue') plt.plot(x_line, line(w)) plt.show() #Plot Ein and Eout plt.title('Ein/Eout Pocket with Linear Regresion Initial Weights') plt.xlabel('Iterations') plt.ylabel('Error %') plt.plot(Ein, label='Ein') plt.plot(Eout, label = 'Eout') plt.legend() plt.show() Please provide all the code, the previous answer was not helpful