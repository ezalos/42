/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyImageCarousel.js                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:40:22 by root              #+#    #+#             */
/*   Updated: 2019/06/04 17:01:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import {
  Image,
  StatusBar,
  StyleSheet,
  Text,
  TouchableWithoutFeedback,
  View,
} from 'react-native';
import ImageCarousel from 'react-native-image-carousel';
import React, {Component} from 'react';
import { colors, borderRadius, fonts, icon, image, padding, margin, dimensions, fontsSize, fontsWeight, fontsFamily } from '../../styles/base.js'


const urls = [
	"https://static.wixstatic.com/media/684e4d_d410acc544e7439bad222dc9700ec972~mv2_d_4032_3024_s_4_2.jpg",
	"https://static.wixstatic.com/media/684e4d_9184550f87a24b5880756880b3b465c3~mv2.jpg",
	"https://static.wixstatic.com/media/684e4d_941c1ca890a74b36956f5a981940a94f~mv2_d_4032_3024_s_4_2.jpg"
];

// const urls = this.props.urls;

class MyImageCarousel extends Component {
  imageCarousel: React$Element<*>;

  componentDidMount() {
    StatusBar.setBarStyle('dark-content');
  }

  captureImageCarousel = (imageCarousel: React$Element<*>) => {
    this.imageCarousel = imageCarousel;
  };

  handleHeaderPress = () => (this.imageCarousel: $FlowFixMe).close();

  renderHeader = (): React$Element<*> => (
    <TouchableWithoutFeedback onPress={this.handleHeaderPress}>
      <View>
        <Text style={styles.closeText}>Exit</Text>
      </View>
    </TouchableWithoutFeedback>
  );

  renderFooter = (): React$Element<*> => (
    <Text style={styles.footerText}>Footer!</Text>
  );

  renderImage = (idx: number) => (
    <Image
      style={StyleSheet.absoluteFill}
      resizeMode="contain"
      source={{uri: this.props.article.imgUrls[idx]}}
    />
  );

  render() {
		const {article} = this.props
    return (
      <View style={styles.container}>
        <View>
          <ImageCarousel
            ref={this.captureImageCarousel}
            renderContent={this.renderImage}
          >
            {article.imgUrls.map(url => (
              <Image
                style={styles.image}
                key={url}
                source={{uri: url, width: 200}}
                resizeMode="cover"
              />
            ))}
          </ImageCarousel>
        </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
  },
  closeText: {
    color: 'white',
    textAlign: 'right',
    padding: 10,
  },
  footerText: {
    color: 'white',
    textAlign: 'center',
  },
  image: {
    height: image.lg_h,
		width: image.xl_w,
  },
});

export default MyImageCarousel;
