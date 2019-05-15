/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.js                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:30:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/11 18:08:25 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// App.js


	// <Provider store={Store}>
	// 	<Navigation/>
	// </Provider>


import React from 'react'
import Navigation from './Navigation/Navigation'
import { Provider } from 'react-redux';
import { LinearGradient } from 'expo';
import ButtonComponent, { CircleButton, RoundButton, RectangleButton } from 'react-native-button-component';
import { StyleSheet, View, Text, Image, TouchableOpacity, Shadow, Button } from 'react-native';
import Store from './Store/configureStore'

export default class App extends React.Component {
  render() {
    return (
			<View style={styles.main_container}>
				<View style={styles.news}>
					<Text style={styles.news_title}>Lorem Ipsum</Text>
					<Text style={styles.news_content}>Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. </Text>
				</View>


	     <View style={styles.big_button}>

	      <TouchableOpacity
	         style={styles.SubmitButtonStyle}
	         activeOpacity = { .5 }
	         onPress={ this.ButtonClickCheckFunction }
	      >

	           <Text style={styles.TextStyle}> AROUND ME </Text>

	     </TouchableOpacity>

	     </View>

				<View style={styles.cat_icons}>
					<View style={styles.dos_elem}>
					<View style={styles.cat_elem}>
						<View style={styles.white_b}>
							<Image
								style={styles.big_icon}
								source={require("./assets/Par'Appetit.png")}
							/>
							</View>
							<Text style={styles.cat_title_b}>Par'Appetit</Text>
						</View>
						<View style={styles.space}/>
						<View style={styles.cat_elem}>
						<View style={styles.white_b}>
							<Image
								style={styles.big_icon}
								source={require("./assets/Par'Ivresse.png")}
							/>
							</View>
							<Text style={styles.cat_title_b}>Par'Ivresse</Text>
						</View>
					</View>

					<View style={styles.tres_elem}>
						<View style={styles.cat_elem}>
						<View style={styles.white_b}>
							<Image
								style={styles.small_icon}
								source={require("./assets/Par'Ailleurs.png")}
							/>
							</View>
							<Text style={styles.cat_title_s}>Par'Ailleurs</Text>
						</View>
						<View style={styles.space}/>
						<View style={styles.cat_elem}>
						<View style={styles.white_b}>
							<Image
								style={styles.small_icon}
								source={require("./assets/Par'Passion.png")}
							/>
							</View>
							<Text style={styles.cat_title_s}>Par'Passion</Text>
						</View>
						<View style={styles.space}/>
						<View style={styles.cat_elem}>
						<View style={styles.white_b}>
							<Image
								style={styles.small_icon}
								source={require("./assets/Par'Gourmandise.png")}
							/>
							</View>
							<Text style={styles.cat_title_s}>Par'Gourmandise</Text>
						</View>
					</View>
				</View>
			</View>
    )
  }
}


const styles = StyleSheet.create({
	main_container: {
		flex: 1,
		marginTop: 25,
		justifyContent: 'space-between',
		backgroundColor: '#ffffff'
	},
		news: {
			height: 50,
			margin: 5,
			backgroundColor: '#ffffff'
		},
			news_title: {
				fontSize: 22,
				textDecorationLine: 'underline',
				color:'#222222',
			},
			news_content: {
				fontSize: 14,
				fontStyle: 'italic',
				color:'#555555',
			},
		big_button: {
	    flex: 1,
	    justifyContent: 'center',
	    backgroundColor: '#fff',
	  },
	  SubmitButtonStyle: {
	    marginTop:10,
	    paddingTop:30,
	    paddingBottom:30,
	    marginLeft:75,
	    marginRight:75,
	    backgroundColor:'#00BCD4',
	    borderRadius:45,
	    borderWidth: 1,
	    borderColor: '#fff'
	  },

	  TextStyle:{
	      color:'#fff',
				fontWeight: 'bold',
				fontSize: 20,
	      textAlign:'center',
	  },
		cat_icons: {
			height: 350,
			margin:15,
			justifyContent: 'space-evenly',
			alignItems: 'center',
			flexDirection: 'column'
		},
		space:{
			width:20
		},
			dos_elem: {
				flexDirection: 'row',
				justifyContent: 'space-between',
				alignItems: 'flex-end',
				flex: 1
			},
			cat_elem:{
				flexDirection: 'column',
				justifyContent: 'center',
			},
			cat_title_b:{
				fontSize: 24,
				fontWeight: 'bold',
				textAlign: 'center',
			},
			cat_title_s:{
				fontSize: 18,
				fontWeight: 'bold',
				textAlign: 'center',
				width:100,
			},
			white_b:{
				backgroundColor:'#fef',
				borderRadius:10,
				shadowOpacity:1,
				elevation: 10,
				shadowColor: 'black',
			},
				big_icon: {
					width: 150,
					height: 150,
					resizeMode: 'contain'
				},
				big_text: {
					flex: 1,
				},
			tres_elem: {
				flexDirection: 'row',
				justifyContent: 'space-evenly',
				alignItems: 'flex-start',
				flex: 1
			},
				small_icon: {
					width: 100,
					height: 100,
					resizeMode: 'contain'
				}
})
