/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SlideShow.js                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:41:27 by root              #+#    #+#             */
/*   Updated: 2019/07/02 21:13:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React, { Component } from 'react';
import { View, Image, ScrollView, Dimensions, Animated } from 'react-native';
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

const width_ = image.xl_w;
const height_ = image.lg_h;

const photos = [
  { uri: 'https://cdn.skillflow.io/resources/img/skillflowninja.png' },
  { uri: 'https://mileung.com/static/media/me.cd114855.png' },
  { uri: 'https://cdn.skillflow.io/resources/img/skillflowninja.png' },
  { uri: 'https://mileung.com/static/media/me.cd114855.png' },
  { uri: 'https://cdn.skillflow.io/resources/img/skillflowninja.png' }
];

export default class Slideshow extends React.Component {
  scrollX = new Animated.Value(0) // this will be the scroll location of our ScrollView

  render() {
    // position will be a value between 0 and photos.length - 1 assuming you don't scroll pass the ends of the ScrollView
    let position = Animated.divide(this.scrollX, width_);
		const {article} = this.props
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <View
          // this will bound the size of the ScrollView to be a square because
          // by default, it will expand regardless if it has a flex value or not
          style={{ width: width_, height: height_ }}
          >
          <ScrollView
            horizontal={true}
            pagingEnabled={true} // animates ScrollView to nearest multiple of it's own width
            showsHorizontalScrollIndicator={false}
            // the onScroll prop will pass a nativeEvent object to a function
            onScroll={Animated.event( // Animated.event returns a function that takes an array where the first element...
              [{ nativeEvent: { contentOffset: { x: this.scrollX } } }] // ... is an object that maps any nativeEvent prop to a variable
            )} // in this case we are mapping the value of nativeEvent.contentOffset.x to this.scrollX
            scrollEventThrottle={16} // this will ensure that this ScrollView's onScroll prop is called no faster than 16ms between each function call
            >
            {article.imgUrls.map((source, i) => { // for every object in the photos array...
              return ( // ... we will return a square Image with the corresponding object as the source
                <Image
                  key={i} // we will use i for the key because no two (or more) elements in an array will have the same index
                  style={{ width: width_, height : height_, resizeMode: 'cover'}}
                  source={{uri : source.replace(".webp", ".png")}}
                />
              );
            })}
          </ScrollView>
        </View>
        <View
          style={{ flexDirection: 'row', position: 'absolute', bottom: 0 }} // this will layout our dots horizontally (row) instead of vertically (column)
          >
          {article.imgUrls.map((_, i) => { // the _ just means we won't use that parameter
            let opacity = position.interpolate({
              inputRange: [i - 1, i, i + 1], // each dot will need to have an opacity of 1 when position is equal to their index (i)
              outputRange: [0.3, 1, 0.3], // when position is not i, the opacity of the dot will animate to 0.3
              // inputRange: [i - 0.50000000001, i - 0.5, i, i + 0.5, i + 0.50000000001], // only when position is ever so slightly more than +/- 0.5 of a dot's index
              // outputRange: [0.3, 1, 1, 1, 0.3], // is when the opacity changes from 1 to 0.3
              extrapolate: 'clamp' // this will prevent the opacity of the dots from going outside of the outputRange (i.e. opacity will not be less than 0.3)
            });
            return (
              <Animated.View // we will animate the opacity of the dots so use Animated.View instead of View here
                key={i} // we will use i for the key because no two (or more) elements in an array will have the same index
                style={{ opacity, height: 10, width: 10, backgroundColor: '#FFF', margin: 8, borderRadius: 5 }}
              />
            );
          })}
        </View>
      </View>
    );
  }
}
